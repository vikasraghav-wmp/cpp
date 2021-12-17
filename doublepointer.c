#include <stdio.h>
int main()
{
    int var = 1000;
    int *ptr1;
    int **ptr2;
    ptr1 = &var;
    ptr2 = &ptr1;
    printf("Value of var = %d\n", var);
    printf("Value of var using single pointer = %d\n", *ptr1);
    printf("Value of var using double pointer = %d\n", **ptr2);
    return 0;
}
