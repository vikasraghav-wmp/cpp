#include <stdio.h>
#include <string.h>
struct employee
{
    int id,salary;
    char name[50];
} e1, e2;
int main()
{
    e1.id = 101;
    strcpy(e1.name, "Vikas Raghav");
    e1.salary = 30000;
    e2.id = 102;
    strcpy(e2.name, "Aakash Tyagi");
    e2.salary = 28000;
    printf("employee 1 id : %d\n", e1.id);
    printf("employee 1 name : %s\n", e1.name);
    printf("employee 1 salary : %d\n", e1.salary);
    printf("employee 2 id : %d\n", e2.id);
    printf("employee 2 name : %s\n", e2.name);
    printf("employee 2 salary : %d\n", e2.salary);
    return 0;
}