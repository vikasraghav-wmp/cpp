#include<stdio.h>
#include<string.h>
int main()
{
    int n=0;
    char ch[200];
    char search[20];
    FILE *ptr;
    ptr=fopen("assign.c", "r");
    if (ptr == NULL)
    {
        printf("File not exist");
    }
    printf("Enter a word to search : ");
    scanf("%s", search);
    while(fscanf(ptr, "%s", ch)!= EOF)
    {
        if(strstr(ch,search))
        {
        printf("word found : %s\n", ch);
        n++;
        }
    }
    printf("Total words : %d", n);
    fclose(ptr);
}