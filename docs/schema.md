# Database Schema (Planned)

The Student Information System uses PostgreSQL as its database.

## students table

| Field       | Type         | Description              |
|------------|--------------|--------------------------|
| id         | SERIAL       | Primary key              |
| name       | VARCHAR(100) | Student full name        |
| email      | VARCHAR(100) | Unique student email     |
| created_at | TIMESTAMP    | Record creation time     |

## Design Notes

- Database schema is planned at design time.
- CRUD operations are implemented at the application layer in C++.
- Schema management is handled programmatically rather than via raw SQL files.
