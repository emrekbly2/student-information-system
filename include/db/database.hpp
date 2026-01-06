#pragma once
#include <string>
#include <pqxx/pqxx>

class Database {
public:
    Database(const std::string& conn_str);

    bool connect();

    void insert_student(
        int id,
        const std::string& name,
        const std::string& surname,
        const std::string& department,
        const std::string& email
    );

    void list_students();

private:
    std::string connection_string;
};
