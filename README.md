# Student Information System

This project is developed as part of the **System Programming** course.  
The goal of the project is to design and implement a containerized, database-backed C++ application that demonstrates core system programming concepts together with modern DevOps practices.

The system is a command-line based Student Information System written in C++, using PostgreSQL as the database, fully containerized with Docker and Docker Compose, and validated through CI pipelines using GitHub Actions.

The project emphasizes:

 - Container-based system design

 - Database connectivity from C++ (libpqxx)

 - Modular CMake-based build systems

 - CI/CD integration

 - Collaborative development using GitHub workflows

---

## Technologies Used
- Ubuntu
- C++ (C++17)
- PostgreSQL
- libpqxx (PostgreSQL C++ client library)
- Docker & Docker Compose
- Git & GitHub
- GitHub Actions (CI/CD)

---

## System Architecture

The system consists of two main Docker containers running on a private Docker network:

1. **PostgreSQL Database Container**
   - Stores student information persistently using Docker volumes
   - Uses Docker volumes for data persistence
   - Configured via environment variables
   - Includes health checks to ensure availability

2. **C++ Application Container**
   - Command-line interface (CLI)
   - Connects to PostgreSQL using `libpqxx`
   - Performs CRUD operations

The containers communicate over a **private Docker network** defined in `docker-compose.yml`.

---

## Features

 - Add student information (ID, name, surname, department, email)
 - List all students
 - Update existing student records
 - Delete student records
 - Database transaction management
 - Error handling and input validation
 - Automated build verification via CI

---

## How to Run

Please see the **INSTALL.md** file for detailed installation and execution instructions.

---

## Docker Images (Public)

All Docker images are publicly available on **Docker Hub** as required by the course guidelines.

### Application , Database Images

- **App+Postgres(Hilal Bizimyer)**
  https://hub.docker.com/repository/docker/hilalb/student-information-system-postgres
  https://hub.docker.com/repository/docker/hilalb/student-information-system-app

- **C++ Application (Ezgi Erdoğan)**  
  https://hub.docker.com/r/ezgierdoganfbu/sis-project-app

- **C++ Application (Emre Kubilay)**  
  https://hub.docker.com/r/emrekubi/student-app


---

## Example Usage (Docker)

```bash
cp .env.example .env
docker compose up -d
