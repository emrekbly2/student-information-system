#include <pqxx/pqxx>
#include <iostream>

int main() {
    try {
        pqxx::connection c(
            "host=localhost port=5432 dbname=test user=test password=test"
        );
        std::cout << "DB connection OK\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
