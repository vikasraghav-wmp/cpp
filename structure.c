#include <stdio.h>
#include <stdlib.h>
struct emp
{
    char name[20];
    int id;
};
int main()
{
struct emp *ptr = NULL, *tmp = NULL;
int range,i;
printf("Enter Range : ");
scanf("%d", &range);
ptr = (struct emp*)malloc(range*sizeof(struct emp));
tmp = ptr;
for ( i = 0; i < range; i++)
{
    printf("Enter name : ");
    scanf("%s", ptr->name);
    printf("Enter id");
    scanf("%d", &ptr->id);
    ptr++;
}
ptr = tmp;
printf("The values you Entered is listed below\n");
for ( i = 0; i < range; i++)
{
    printf("Name = %s\n", ptr->name);
    printf("Id = %d\n", ptr->id);
    ptr++;
}
ptr = tmp;
free(ptr);
}
