#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// struct student
// {
//     int age = 15;
//     char name[10] = "arvind";
//     int class = 12;
// };

// void getData(struct student *arvind)
// {
//     printf("age is:%d\n", arvind->age);
// }

int main()
{
    struct student
    {
        int age = 15;
        char name[10] = "arvind";
        int class = 12;
    };
    struct student *kid;
    kid = (struct student *)malloc(sizeof(struct student));
    // getData(kid);
    printf("age is:%d\n", arvind->age);
    return 0;
}