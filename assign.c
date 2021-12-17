#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,count;
    char **ptr;
    printf("Enter total no of String:");
    scanf("%d", &count);
    ptr = (char**) malloc(count*sizeof(char*));
    for(i=0;i<count;i++)
    {
    printf("Enter the content%d:",i+1);
        ptr[i]=(char*)malloc(5*sizeof(char*));
        scanf("%s",ptr[i]);
    }
    for ( i = 0; i < count; i++)
    {
        printf("%s\n",ptr[i]);
    }
    for(i=0;i<count;i++)
    {
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}
