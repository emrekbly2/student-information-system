## Memory Leak Test

The application was tested using Valgrind with basic CRUD operations.
No critical memory leaks were observed during the test.

Valgrind command used:
valgrind --leak-check=full ./sis_app

Memory leak tests can be extended in future iterations.
