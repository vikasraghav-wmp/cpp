#include<stdio.h>
int main()
{
    FILE *ptr;
    char ch;
    ptr=fopen("fibo.c", "r");
    if( ptr == NULL)
    {
        printf("Can not find ");
    }
    while(1)
    {
        ch=fgetc(ptr);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
        
    }
    fclose(ptr);
}