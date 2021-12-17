#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char ch[100];
    printf("Enter string");
    fgets(ch, 20, stdin);
    puts(ch);
    n=strlen(ch);
    printf("%d", n);
    }
    str