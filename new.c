#include <stdio.h>
#include <stdlib.h>
struct student
{
    int rollno;
    char name[20];
};
struct student *ptr;
void display(struct student *ptr,int count);
int main()
{
    int i, count;
    printf("Enter the range");
    scanf("%d", &count);
    ptr = (struct student *)malloc(count * sizeof(struct student));
    for (i = 0; i < count; i++)
    {
        printf("Enter name of student %d : ", i + 1);
        scanf("%s", ptr->name);
        printf("Enter roll no of student %d : ", i + 1);
        scanf("%d", &ptr->rollno);
    }
    display(ptr, count);
}
    void display(struct student *ptr, int count)
    {
        for (int i = 0; i < count; i++)
        {
            printf("name : %s", ptr->name);
            printf("roll no : %d ", ptr->rollno);
        }
        
    }