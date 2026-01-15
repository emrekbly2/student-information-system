# User Manual – Student Information System

## 1. Overview

This application is a **command-line based Student Information System (SIS)** developed in C++.  
It allows users to perform basic **CRUD (Create, Read, Update, Delete)** operations on student records stored in a PostgreSQL database.

The system is designed with:
- Modular C++ architecture
- Database abstraction layer
- Input validation
- Automated tests and CI integration

Target users:
- Developers
- Teaching assistants
- Students evaluating database-driven C++ applications

---

## 2. System Requirements

Before running the application, ensure the following are installed:

- C++17 compatible compiler (GCC / Clang)
- PostgreSQL (local or Docker-based)
- libpqxx library
- CMake (>= 3.10)
- Docker & Docker Compose (optional, recommended)

---

## 3. Application Architecture (High-Level)

The application follows a layered structure:

- **Presentation Layer**  
  Handles CLI-based user interaction and menu navigation.

- **Application Layer**  
  Processes user commands and validates inputs.

- **Database Layer**  
  Encapsulates PostgreSQL operations using `libpqxx`.

This separation improves maintainability, testability, and scalability.

---

## 4. Menu Options

When the application starts, the following menu is displayed:

1. Insert Student  
2. List Students  
3. Update Student  
4. Delete Student  
5. Exit  

Each operation is executed synchronously and provides feedback to the user.

---

## 5. Functional Descriptions

### 5.1 Insert Student
Adds a new student record to the database.

Required fields:
- Student ID (integer, unique)
- Name (string)
- Surname (string)
- Department (string)
- Email (must be valid format)

Validation:
- Duplicate IDs are rejected
- Email format is validated before insertion

---

### 5.2 List Students
Displays all student records currently stored in the database.

Output includes:
- ID
- Name
- Surname
- Department
- Email

---

### 5.3 Update Student
Updates an existing student record by ID.

Rules:
- Student ID must already exist
- All fields are replaced with new values

---

### 5.4 Delete Student
Deletes a student record by ID.

Behavior:
- If ID does not exist, operation is safely rejected
- Deletion is permanent

---

## 6. Database Schema

The system uses a single table:

**students**
- id (INT, PRIMARY KEY)
- name (TEXT)
- surname (TEXT)
- department (TEXT)
- email (TEXT)

---

## 7. Error Handling

The application handles the following error cases:

- Database connection failures
- Invalid email formats
- Non-existent student IDs
- SQL execution errors

All errors are logged to the console with descriptive messages.

---

## 8. Testing & Validation

### Unit Tests
- Email validation logic
- Database CRUD operations

### Integration Tests
- Sequential CRUD flow:
  1. Insert student
  2. List students
  3. Update student
  4. List students
  5. Delete student
  6. List students again

### Memory Leak Testing
- Tested using Valgrind
- No critical memory leaks detected

---

## 9. Limitations & Future Improvements

Current limitations:
- CLI-only interface
- Single-table schema
- No authentication or role management

Planned improvements:
- Multi-table relational schema
- User authentication
- REST API layer
- GUI or web interface

---

## 10. Exit Behavior

Selecting **Exit** safely terminates the application and closes database connections.

---

## 11. Conclusion

This project demonstrates:
- C++ database integration
- Modular software design
- CI-supported development
- Documentation-driven delivery

It is suitable for academic evaluation and further extension.
