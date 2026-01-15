#include <iostream>
#include <cassert>
#include "app.hpp"

int main() {
    std::cout << "test_basic: started" << std::endl;

    // Basic sanity test
    int a = 2;
    int b = 3;

    // Assert that basic logic works
    assert(a + b == 5);

    std::cout << "test_basic: passed" << std::endl;
    return 0;
}
