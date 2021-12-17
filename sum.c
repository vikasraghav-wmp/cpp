#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* root = NULL;

void addatlast()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* temp2;
        temp2 = root;

        while ( temp2->link != NULL)
        {
            temp2 = temp2->link;
        }

        temp2->link = temp;
    }
}

void addatbegining()
{

}

void addatafter()
{
    int loc,len;
    struct node* temp;
    printf("Enter location");
    scanf("%d", &loc);
    len=length();
    if( loc>len)
    {
        printf("Invalid location");
    }
    else
    {
        temp1=root;
        while (i<loc)
        {
            temp1=temp1->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
    }
}

void length()
{

}

void display()
{
    struct node* temp;
    temp = root;
    if(temp == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while ( temp != Null )
        {
            printf("%d---" &temp->data);
            temp = temp->link;
        }
        printf("\n\n")
    }

}

void deletenode()
{
    int loc;
    struct node* temp;
    printf("Enter the location to delete");
    scanf("%d", &loc);

    if( loc > length() )
    {
        printf("Invalid Location");
    }

    elseif( loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }

    else
    {
        struct node* temp1 = root, temp2*;
        int i;
        while (i>loc-1)
        {
            temp1 = temp1->link;
            i++;
        }
        temp2=temp1->link;
        temp1->link = temp2->link;
        temp2->link = NULL;
        free(temp2);
    }

}

void main()
{
    int ch;
    while (1)
    {
        printf("Single linked list operations : \n");
        printf("1.Add at last \n");
        printf("2. Add at begining \n");
        printf("3. Add at after \n");
        printf("4. Display \n");
        printf("5. Delete a Node \n");
        printf("6. Length \n")
        printf("6. Quit \n");
        printf("Enter choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addatlast();
            break;

        case 2:
            addatbegining();
            break;

        case 3:
            addatafter();
            break;

        case 4:
            display();
            break;

        case 5:
            deletenode();
            break;

        case 6:
            exit(1);

        default:
            printf("You have entered the wrong choice")
        }
    }
}