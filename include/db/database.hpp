#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <pqxx/pqxx>

class Database {
private:
    std::string connection_string;

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

    void update_student(
        int id,
        const std::string& name,
        const std::string& surname,
        const std::string& department,
        const std::string& email
    );

    void delete_student(int id);
};

#endif
