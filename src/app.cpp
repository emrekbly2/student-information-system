#include "app.hpp"
#include "db/database.hpp"
#include <iostream>
#include <regex>
#include <string>

// ----------------------------
// Email validation helper
// ----------------------------
bool is_valid_email(const std::string& email) {
    const std::regex pattern(
        R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))"
    );
    return std::regex_match(email, pattern);
}

// ----------------------------
// Main application logic
// ----------------------------
void run_app() {
    try {
        std::string conn =
            "host=localhost port=5432 dbname=sis user=sis_user password=sis_pass";

        Database db(conn);

        if (!db.connect()) {
            std::cerr << "❌ Cannot connect to database\n";
            return;
        }

        int choice;
        std::cout
            << "\n===== Student Information System =====\n"
            << "1) Insert student\n"
            << "2) List students\n"
            << "3) Update student\n"
            << "4) Delete student\n"
            << "Choice: ";

        std::cin >> choice;

        if (choice == 1) {
            int id;
            std::string name, surname, dept, email;

            std::cout << "ID: "; std::cin >> id;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Surname: "; std::cin >> surname;
            std::cout << "Department: "; std::cin >> dept;
            std::cout << "Email: "; std::cin >> email;

            if (!is_valid_email(email)) {
                std::cerr << "❌ Invalid email format\n";
                return;
            }

            db.insert_student(id, name, surname, dept, email);
            std::cout << "✅ Student inserted successfully\n";
        }

        else if (choice == 2) {
            db.list_students();
        }

        else if (choice == 3) {
            int id;
            std::string name, surname, dept, email;

            std::cout << "ID: "; std::cin >> id;
            std::cout << "New name: "; std::cin >> name;
            std::cout << "New surname: "; std::cin >> surname;
            std::cout << "New department: "; std::cin >> dept;
            std::cout << "New email: "; std::cin >> email;

            if (!is_valid_email(email)) {
                std::cerr << "❌ Invalid email format\n";
                return;
            }

            db.update_student(id, name, surname, dept, email);
            std::cout << "✅ Student updated successfully\n";
        }

        else if (choice == 4) {
            int id;
            std::cout << "ID: ";
            std::cin >> id;

            db.delete_student(id);
            std::cout << "✅ Student deleted successfully\n";
        }

        else {
            std::cerr << "❌ Invalid choice\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Runtime error: " << e.what() << "\n";
    }
}
