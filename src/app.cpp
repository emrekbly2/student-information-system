#include "app.hpp"
#include "db/database.hpp"
#include <iostream>
#include <string>

void run_app() {
    std::string conn =
        "host=localhost port=5432 dbname=sis user=sis_user password=sis_pass";

    Database db(conn);

    if (!db.connect()) {
        std::cerr << "Cannot connect to database\n";
        return;
    }

    int choice;
    std::cout
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

        db.insert_student(id, name, surname, dept, email);
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

        db.update_student(id, name, surname, dept, email);
    }
    else if (choice == 4) {
        int id;
        std::cout << "ID: ";
        std::cin >> id;
        db.delete_student(id);
    }
    else {
        std::cout << "Invalid choice\n";
    }
}
