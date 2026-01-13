# Installation Guide

## Requirements

- Ubuntu 20.04 or newer
- Docker
- Docker Compose
- Git

## Setup Steps

1. Clone the project repository.
2. Navigate to the project directory.
3. Run the following command:
   docker-compose up
4. Use the application through the command-line interface.

# Verify installation:
```bash
docker --version
docker compose version

```

## Environment Setup
 - Create the environment file from the template:
```bash
cp .env.example .env
```
 -Do NOT commit the .env file to the repository.

 - Start the System
 ```bash
docker compose up -d
```
- Verify running containers and the db service must be in healthy state.
 ```bash
docker compose ps
```
-Database Access and Verification

PostgreSQL tables and student data can only be accessed from inside the database container.

Enter the database container
```bash
docker compose exec db bash

```
- Connect to the database:
```bash
psql -U sis_user -d sis
```
 - List database tables:
```bash
\dt
```
 - View student records:
```bash
SELECT * FROM students;
```
 - Exit PostgreSQL:
```bash
\q
```


## Notes
- The database runs in a separate Docker container.
- All configuration is managed using Docker Compose.
