# Student Record Management System

A console-based **Student Record Management System** developed using **C++** as a Data Structures and Algorithms (DSA) project. This application allows users to manage student records efficiently using a Singly Linked List and Stack.

Project Overview:

The Student Record Management System is designed to perform basic student record operations through a menu-driven interface. It demonstrates the practical implementation of data structures such as Linked Lists and Stacks, along with searching and sorting algorithms.

**Note:** Student records are stored temporarily in memory. All records are lost when the program is closed.

Features:

- Add new student records
- Display all student records
- Search students using Roll Number
- Update existing student information
- Delete student records
- Sort students by marks in descending order
- Find the student with the highest marks (Topper)
- Count total students
- Undo the last deletion
- Prevent duplicate Roll Numbers
- Menu-driven console interface

Technologies Used:

- **Programming Language:** C++
- **Compiler:** GCC / MinGW
- **IDE:** VS Code
- **Concepts:** Data Structures and Algorithms

DSA Concepts Implemented:

| Concept | Application |
|---|---|
| Singly Linked List | Dynamic storage and management of student records |
| Stack | Undo the last deletion |
| Linear Search | Search student by Roll Number |
| Bubble Sort | Sort students by marks |
| Traversal | Display and count student records |
| Pointers | Connect linked-list nodes |
| Dynamic Memory Allocation | Allocate and release memory using `new` and `delete` |

## 📂 Project Structure

```text
Student-Record-Management-System/
│
├── StudentManagement.cpp
├── README.md
└── .gitignore
```

## ⚙️ How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/Student-Record-Management-System.git
```

### Step 2: Open the Project Folder

```bash
cd Student-Record-Management-System
```

### Step 3: Compile the Program

```bash
g++ StudentManagement.cpp -o StudentManagement
```

### Step 4: Run the Program

**Windows:**
```bash
StudentManagement.exe
```

**Linux / macOS:**
```bash
./StudentManagement
```

## 📋 Menu Options

1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Sort Students by Marks
7. Find Topper
8. Count Total Students
9. Undo Last Deletion
10. Exit

## ⏱️ Time Complexity

| Operation | Time Complexity |
|---|---|
| Add Student | O(n) |
| Display Students | O(n) |
| Search Student | O(n) |
| Update Student | O(n) |
| Delete Student | O(n) |
| Sort Students | O(n²) |
| Find Topper | O(n) |
| Count Students | O(n) |
| Undo Deletion | O(n) |

*Undo deletion takes O(n) in this implementation because it checks for duplicate Roll Numbers before restoring the record.*

## 👨‍💻 Project Team

| Name | Roll Number | Role |
|---|---|---|
| Harshit Kumar | 2546124 | Team Leader |
| Manish Kumar | 2546161 | Team Member |
| Niraj Kumar Sharma | 2546190 | Team Member |
| Mukul Kumar Singh | 2546178 | Team Member |

## 🚀 Future Improvements

- Add file handling or database connectivity