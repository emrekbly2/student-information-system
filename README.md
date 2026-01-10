# Student Information System

This project is developed as part of the **System Programming** course.  
It is a **command-line based Student Information System** implemented in **C++**, running on **Docker containers**, and using **PostgreSQL** as the database.

The project focuses on system programming concepts such as containerization, database connectivity, modular C++ design, CI/CD, and collaborative development using GitHub.

---

## Technologies Used
- Ubuntu
- C++ (C++17)
- PostgreSQL
- Docker & Docker Compose
- Git & GitHub
- libpqxx (PostgreSQL C++ client library)

---

## System Architecture

The system consists of **two main Docker containers**:

1. **PostgreSQL Database Container**
   - Stores student information persistently using Docker volumes

2. **C++ Application Container**
   - Command-line interface (CLI)
   - Connects to PostgreSQL using `libpqxx`
   - Performs CRUD operations

The containers communicate over a **private Docker network** defined in `docker-compose.yml`.

---

## Features

- Add student information  
  (ID, name, surname, department, email)
- List all students
- Update student information
- Delete student information
- Database transaction management
- Error handling and input validation

---

## How to Run

Please see the **INSTALL.md** file for detailed installation and execution instructions.

---

## Docker Images (Public)

All Docker images are publicly available on **Docker Hub** as required by the course guidelines.

### Application Images
- **C++ Application (Ezgi Erdoğan)**  
  https://hub.docker.com/r/ezgierdoganfbu/sis-project-app

- **C++ Application (Emre Kubilay)**  
  https://hub.docker.com/r/emrekubi/student-app

### Database Image
- **PostgreSQL Database**  
  https://hub.docker.com/r/hilalb/student-information-system-postgres

---

## Example Usage (Docker)

```bash
cp .env.example .env
docker compose up -d
