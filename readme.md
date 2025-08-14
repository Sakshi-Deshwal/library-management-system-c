# 📚 Library Management System (C)

A simple **Library Management System** implemented in C using **file handling** and **structures**.  
This program allows you to manage a collection of books — add, view, search, update, and delete records — all stored in a text file.

---

## ✨ Features
- ➕ **Add new book** — ID, Title, Author, Quantity
- 📖 **View all books** — Displays all records from file
- 🔍 **Search a book** — By ID
- 🗑 **Delete a book** — By ID
- ✏ **Update a book** — Modify title, author, or quantity
- 💾 **Persistent storage** — Uses text file (`letter.txt`) for data

---

## 🛠 Technologies Used
- **C Programming Language**
- **File I/O** (`fopen`, `fprintf`, `fgets`, `fclose`)
- **Structures** for book representation
- **String handling** (`fgets`, `strcspn`, `strcasecmp`)

---

## 📂 File Structure
```

library-management-system/
│
├── library.c          # Main C program
├── letter.txt         # Data storage file
└── README.md          # Project documentation

````

---

## 🚀 How to Run

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/library-management-system.git
   cd library-management-system
````

2. **Compile the Program**

   ```bash
   gcc library.c -o library
   ```

3. **Run the program**

   ```bash
   ./library
   ```

---

## 📋 Requirements

* GCC compiler
* C standard library
* Works on **Windows**, **Linux**, **macOS**

---

## 🗂 Sample Data (`letter.txt`)

```
1|The Alchemist|Paulo Coelho|5
2|C Programming|Dennis Ritchie|3
```

---

## 🙌 Author

**Sakshi**
💡 *"Code is like a library — it’s only useful when it’s well-organized."*

```
