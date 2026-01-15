## Memory Leak Test

The application was tested using Valgrind with basic CRUD operations.
No critical memory leaks were observed during the test.

Valgrind command used:
valgrind --leak-check=full ./sis_app

Memory leak tests can be extended in future iterations.

## Integration Test Scenario

The following sequential CRUD operations were tested via CLI:

1. Insert a student
2. List students
3. Update the student
4. List students
5. Delete the student
6. List students again

All operations executed successfully in sequence.
