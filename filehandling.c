#include <stdio.h>
#include<string.h>
int main()
{
    FILE *ptr;
    char str[100];

    printf("Enter string you want to insert in file: ");
    fgets(str, sizeof(str), stdin);
    ptr=fopen("fibo.c", "w");
    if (ptr == NULL)
    {
        printf("File not found");
    }
    if ( strlen ( str ) > 0 )
        {
            fputs(str, ptr);
        }
         
        fclose(ptr);
        printf("Data successfully written");


        return 0;
}
