#include<stdio.h>
int main()
{
int number=50;
int *p;
p=&number;
printf("Address of p variable is %p \n",p);
printf("Address of number variable is %p \n",&number);
printf("Value of p variable is %d \n",*p);
return 0;
}