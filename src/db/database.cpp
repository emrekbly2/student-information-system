#include "db/database.hpp"
#include <iostream>

/* Constructor */
Database::Database(const std::string& conn_str)
    : connection_string(conn_str) {}

/* Connection test */
bool Database::connect() {
    try {
        pqxx::connection c(connection_string);
        if (c.is_open()) {
            std::cout << "Database connection successful\n";
            return true;
        }
    } catch (const std::exception& e) {
        std::cerr << "Connection error: " << e.what() << "\n";
    }
    return false;
}

/* INSERT */
void Database::insert_student(
    int id,
    const std::string& name,
    const std::string& surname,
    const std::string& department,
    const std::string& email
) {
    try {
        pqxx::connection c(connection_string);
        pqxx::work txn(c);

        txn.exec_params(
            "INSERT INTO students (id, name, surname, department, email) "
            "VALUES ($1, $2, $3, $4, $5)",
            id, name, surname, department, email
        );

        txn.commit();
        std::cout << "Student inserted successfully\n";
    } catch (const std::exception& e) {
        std::cerr << "Insert error: " << e.what() << "\n";
    }
}

/* LIST */
void Database::list_students() {
    try {
        pqxx::connection c(connection_string);
        pqxx::nontransaction txn(c);

        pqxx::result r = txn.exec("SELECT * FROM students");

        for (const auto& row : r) {
            std::cout
                << row["id"].as<int>() << " | "
                << row["name"].c_str() << " | "
                << row["surname"].c_str() << " | "
                << row["department"].c_str() << " | "
                << row["email"].c_str() << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "List error: " << e.what() << "\n";
    }
}

/* UPDATE */
void Database::update_student(
    int id,
    const std::string& name,
    const std::string& surname,
    const std::string& department,
    const std::string& email
) {
    try {
        pqxx::connection c(connection_string);
        pqxx::work txn(c);

        txn.exec_params(
            "UPDATE students SET name=$1, surname=$2, department=$3, email=$4 WHERE id=$5",
            name, surname, department, email, id
        );

        txn.commit();
        std::cout << "Student updated successfully\n";
    } catch (const std::exception& e) {
        std::cerr << "Update error: " << e.what() << "\n";
    }
}

/* DELETE */
void Database::delete_student(int id) {
    try {
        pqxx::connection c(connection_string);
        pqxx::work txn(c);

        txn.exec_params(
            "DELETE FROM students WHERE id=$1",
            id
        );

        txn.commit();
        std::cout << "Student deleted successfully\n";
    } catch (const std::exception& e) {
        std::cerr << "Delete error: " << e.what() << "\n";
    }
}
