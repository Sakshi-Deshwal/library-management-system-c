#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Book Structure
struct book
{
    int id;
    char title[56];
    char author[56];
    int quantity;
};

//To Add Books in the library

void addBook()              
{
    struct book b1;
    FILE *ptr;
    ptr = fopen("letter.txt", "a");
    printf("Enter the book id : \n");
    scanf("%d", &b1.id);   
    getchar();
    printf("Enter the book title : \n");
    fgets(b1.title, sizeof(b1.title), stdin);
    b1.title[strcspn(b1.title, "\n")] = '\0';
    printf("Enter the book author : \n");
    fgets(b1.author, sizeof(b1.author), stdin);
    b1.author[strcspn(b1.author, "\n")] = '\0';
    printf("Enter the book Quantity or copies : \n");
    scanf("%d", &b1.quantity);
    fprintf(ptr, "%d|%s|%s|%d\n", b1.id, b1.title, b1.author, b1.quantity);
    fclose(ptr);
    printf("Book added successfully!\n");
}

//View all the books

void viewBook()             
{
    struct book b1;
    int result;
    char line[200];
    FILE *ptr;
    ptr = fopen("letter.txt", "r");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        result = sscanf(line, "%d|%49[^|]|%49[^|]|%d", &b1.id, b1.title, b1.author, &b1.quantity);

        if (result == 4)
        {
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n\n", b1.id, b1.title, b1.author, b1.quantity);
        }
        else
        {
            break;
        }
    }
    fclose(ptr);
}

// Search a book (by ID or Title)

void searchBook()           
{
    struct book b1;
    int found = 0, id, result , choice;
    char line[200] , title[56];
    FILE *ptr;
    ptr = fopen("letter.txt", "r");
    if (ptr == NULL)
    {
        printf("Error opening the file");
        return;
    }

    printf("Search by:\n1. ID\n2. Title\nEnter choice: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);
    } else if (choice == 2) {
        printf("Enter Book Title: ");
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
    } else {
        printf("Invalid choice.\n");
        fclose(ptr);
        return;
    }

    
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        result = sscanf(line, "%d|%49[^|]|%49[^|]|%d", &b1.id, b1.title, b1.author, &b1.quantity);

        if (result == 4)
        {
            if ((choice == 1 && b1.id == id) ||(choice == 2 && strcasecmp(b1.title, title) == 0))
            {
                found++;
                printf("The book id is : %d\n", b1.id);
                printf("The book Title is : %s\n", b1.title);
                printf("The book Author is : %s\n", b1.author);
                printf("The book Quantity or Copies is : %d\n", b1.quantity);
                break;
            }
        }
        else
        {
            break;
            ;
        }
    }
    if (found == 0)
    {
        printf("Book Not Found.");
        return;
    }
    fclose(ptr);
}

// Delete a book by ID

void DeleteBook()         
{
    int delid , result , found = 0;
    struct book b1;
    char line[200];
    FILE *ptr;
    FILE *tempPtr = NULL;
    printf("Enter the id you want to Delete : \n");
    scanf("%d", &delid);
    tempPtr = fopen("letter1.txt", "w");
    ptr = fopen("letter.txt", "r");
    if (ptr == NULL)
    {
        printf("Error opening File\n");
        return;  
    }
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        result = sscanf(line, "%d|%49[^|]|%49[^|]|%d", &b1.id, b1.title, b1.author, &b1.quantity);
        if (result == 4)
        {
            found++;
            if (b1.id != delid)
            {
                fprintf(tempPtr, "%d|%s|%s|%d\n", b1.id, b1.title, b1.author, b1.quantity);
            }
        }
        else
        {
            break;
        }
    }
    fclose(tempPtr);
    fclose(ptr);
    remove("letter.txt");
    rename("letter1.txt", "letter.txt");

    if (found)
        printf("Book deleted successfully.\n");
    else
        printf("Book not found.\n");
}

// Update a book's details

void updateBook()
{
    int upid, found = 0;
    struct book b1;
    char line[200];

    printf("Enter Book ID to update: ");
    scanf("%d", &upid);
    getchar();

    FILE *ptr = fopen("letter.txt", "r");
    FILE *tempPtr = fopen("letter1.txt", "w");
    if (!ptr || !tempPtr) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), ptr)) {
        if (sscanf(line, "%d|%[^|]|%[^|]|%d", &b1.id, b1.title, b1.author, &b1.quantity) == 4) {
            if (b1.id == upid) {
                printf("Enter new title: ");
                fgets(b1.title, sizeof(b1.title), stdin);
                b1.title[strcspn(b1.title, "\n")] = '\0';

                printf("Enter new author: ");
                fgets(b1.author, sizeof(b1.author), stdin);
                b1.author[strcspn(b1.author, "\n")] = '\0';

                printf("Enter new quantity: ");
                scanf("%d", &b1.quantity);
                getchar();
                found = 1;
            }
            fprintf(tempPtr, "%d|%s|%s|%d\n", b1.id, b1.title, b1.author, b1.quantity);
        }
    }

    fclose(ptr);
    fclose(tempPtr);
    remove("letter.txt");
    rename("letter1.txt", "letter.txt");

    if (found)
        printf("Book updated successfully.\n\n");
    else
        printf("Book not found.\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("Welcome to Sakshi's Library\n");
        printf("What you want to do:\n");
        printf("1. Add new book\n2. View all books\n3. Search a book\n4. Delete a book\n5. Update the books\n6. Exit\n Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            viewBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            DeleteBook();
            break;
        case 5:
            updateBook();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    return 0;
}