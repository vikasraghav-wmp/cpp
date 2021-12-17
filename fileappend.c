#include<stdio.h>
#include<string.h>
int main()
{
    FILE *ptr;
    char ch[100];
    char update;
    printf("Enter string to add on file : ");
    fgets(ch, sizeof(ch), stdin);
    ptr=fopen("fibo.c", "a");
    if (ptr == NULL)
    {
        printf("File not found");
    }
    if ( strlen (ch) > 0)
    {
        fputs(ch, ptr);
    }
    fclose(ptr);
    ptr=fopen("fibo.c", "r");
    printf("file successfully updated\n");
    printf("Updated file :  ");
    while(1)
    {
    update=fgetc(ptr);
    if (update == EOF)
    {
        break;
    }
    printf("%c", update);

    }
    fclose(ptr);


}