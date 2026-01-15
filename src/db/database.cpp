#include "db/database.hpp"
#include <iostream>
#include <regex>

/* Constructor */
Database::Database(const std::string& conn_str)
    : connection_string(conn_str), conn(nullptr) {}

/* Destructor */
Database::~Database() {
    if (conn) {
        delete conn;
        conn = nullptr;
    }
}

/* Email validation helper */
bool Database::is_valid_email(const std::string& email) const {
    const std::regex pattern(R"((\w+)(\.|\w)*@(\w+)\.(\w+))");
    return std::regex_match(email, pattern);
}

/* Connection test */
bool Database::connect() {
    try {
        conn = new pqxx::connection(connection_string);
        if (conn->is_open()) {
            std::cout << "Database connection successful\n";
            return true;
        }
    } catch (const std::exception& e) {
        std::cerr << "Connection error: " << e.what() << "\n";
    }
    return false;
}

/* INSERT */
bool Database::insert_student(
    int id,
    const std::string& name,
    const std::string& surname,
    const std::string& department,
    const std::string& email
) {
    if (!is_valid_email(email)) {
        std::cerr << "Invalid email format\n";
        return false;
    }

    try {
        pqxx::work txn(*conn);

        txn.exec_params(
            "INSERT INTO students (id, name, surname, department, email) "
            "VALUES ($1, $2, $3, $4, $5)",
            id, name, surname, department, email
        );

        txn.commit();
        std::cout << "Student inserted successfully\n";
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Insert error: " << e.what() << "\n";
    }
    return false;
}

/* LIST */
void Database::list_students() {
    try {
        pqxx::nontransaction txn(*conn);
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
bool Database::update_student(
    int id,
    const std::string& name,
    const std::string& surname,
    const std::string& department,
    const std::string& email
) {
    if (!is_valid_email(email)) {
        std::cerr << "Invalid email format\n";
        return false;
    }

    try {
        pqxx::work txn(*conn);

        txn.exec_params(
            "UPDATE students SET name=$1, surname=$2, department=$3, email=$4 WHERE id=$5",
            name, surname, department, email, id
        );

        txn.commit();
        std::cout << "Student updated successfully\n";
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Update error: " << e.what() << "\n";
    }
    return false;
}

/* DELETE */
bool Database::delete_student(int id) {
    try {
        pqxx::work txn(*conn);

        txn.exec_params(
            "DELETE FROM students WHERE id=$1",
            id
        );

        txn.commit();
        std::cout << "Student deleted successfully\n";
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Delete error: " << e.what() << "\n";
    }
    return false;
}
