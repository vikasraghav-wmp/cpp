#include<stdio.h>
#include<string.h>
int main()
{
    char *c;
    char a[20]={"My name is vikas"};
    char b[20]={"name"};
    c=strstr(a,b);
    printf("%s",c);
}