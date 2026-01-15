cmake_minimum_required(VERSION 3.22)

project(student_information_system LANGUAGES CXX)

# -----------------------------
# C++ standard
# -----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# libpqxx dependency
# -----------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(
    ${PQXX_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

# -----------------------------
# Core library
# -----------------------------
add_library(sis_core
    src/app.cpp
    src/db/database.cpp
)

target_link_libraries(sis_core
    ${PQXX_LIBRARIES}
)

# -----------------------------
# Main application
# -----------------------------
add_executable(sis_app
    src/main.cpp
)

target_link_libraries(sis_app
    sis_core
    ${PQXX_LIBRARIES}
)

# -----------------------------
# Hello World example (Week 2)
# -----------------------------
add_executable(hello_app
    src/hello.cpp
)

# -----------------------------
# Database connection test
# -----------------------------
add_executable(db_test
    src/db/db_test.cpp
)

target_link_libraries(db_test
    pqxx
    pq
)

# -----------------------------
# Tests (optional)
# -----------------------------
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_executable(test_basic tests/test_basic.cpp)
    add_test(NAME basic_test COMMAND test_basic)
endif()
