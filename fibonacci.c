#include <stdio.h>
#include <stdlib.h>
struct emp 
{
    char name[20];
    int id;
    float salary;
    char designation[20];
};
int main()
{
    int n,i;
    struct emp *ptr=NULL, *tmp=NULL;
    printf("Enter the range of variable");
    scanf("%d", &n);
    ptr=(struct emp*)malloc(n*sizeof(struct emp));
    tmp=ptr;
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of employee %d : ",i+1);
        scanf("%s", ptr->name);
        printf("Enter the id of employee %d : ", i+1);
        scanf("%d", &ptr->id);
        printf("Enter the designation of employee %d : ", i+1);
        scanf("%s", ptr->designation);
        printf("Enter the salary of employee %d : ", i+1);
        scanf("%f", &ptr->salary);
        ptr++;
    }
    ptr=tmp;
    for ( i = 0; i < n; i++)
    {
        printf("Name of employee %d is : %s \n",i+1, ptr->name);
        printf("Id of employee %d is : %d \n", i+1, ptr->id);
        printf("Designation of employee %d is : %s \n", i+1, ptr->designation);
        printf("Salary of employee %d is : %f : ", i+1, ptr->salary);
        ptr++;
    }
    ptr=tmp;
    free(ptr);
    
}