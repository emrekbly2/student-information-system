#include "app.hpp"
#include "db/database.hpp"
#include <iostream>

void run_app() {
    std::string conn =
        "host=localhost port=5432 dbname=sis user=sis_user password=sis_pass";

    Database db(conn);

    if (!db.connect()) {
        std::cerr << "Cannot connect to database\n";
        return;
    }

    int choice;
    std::cout << "1) Insert student\n2) List students\nChoice: ";
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
}
