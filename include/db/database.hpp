#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <pqxx/pqxx>

class Database {
private:
    std::string connection_string;
    pqxx::connection* conn;

    // Internal helper for validation
    bool is_valid_email(const std::string& email) const;

public:
    // Constructor / Destructor
    explicit Database(const std::string& conn_str);
    ~Database();

    // Connection management
    bool connect();

    // CRUD operations
    bool insert_student(
        int id,
        const std::string& name,
        const std::string& surname,
        const std::string& department,
        const std::string& email
    );

    void list_students();

    bool update_student(
        int id,
        const std::string& name,
        const std::string& surname,
        const std::string& department,
        const std::string& email
    );

    bool delete_student(int id);
};

#endif // DATABASE_HPP
