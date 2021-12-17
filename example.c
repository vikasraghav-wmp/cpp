#include <stdio.h>
#include <stdlib.h>
//Represent a node of singly linked list
struct node
{
    int data;
    struct node *next;
};

//Represent the head and tail of the singly linked list
struct node *head, *tail = NULL;

//addNode() will add a new node to the list
void addNode()
{
    int data, num;
    //Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

    //Checks if the list is empty
    if (head == NULL)
    {
        //If list is empty, both head and tail will point to new node
        head = newNode;
        tail = newNode;
    }
    else
    {
        //newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        //newNode will become new tail of the list
        tail = newNode;
    }
}

//display() will display all the nodes present in the list
void display()
{
    //Node current will point to head
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of singly linked list: \n");
    while (current != NULL)
    {
        //Prints each node by incrementing pointer
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void countNodes()
{
    int count = 0;
    //Node current will point to head
    struct node *current = head;

    while (current != NULL)
    {
        //Increment the count by 1 for each node
        count++;
        current = current->next;
    }
    printf("%d \n", count);
}

int main()
{
    int ch;
    while (1)
    {
        printf("Single linked list operations : \n");
        printf("1. Display \n");
        printf("2. count Total Nodes \n");
        printf("3. Add at begining \n");
        printf("4. Delete from Start \n");
        printf("5. Delete from mid \n");
        printf("6. Delete from End \n");
        printf("7. Add in mid \n");
        printf("8. Add in mid \n");
        printf("9. Exit \n");
        printf("Enter choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            display();
            continue;

        case 2:
            countNodes();
            continue;

        case 3:
            addNode();
            continue;
            /*
        case 4:
            deleteFromStart();
            printf("Node is deleted from start \n");
            printf("Updated list = ");
            display();
            break;

        case 5:
            deleteFromMid();
            printf("Node is deleted from mid \n");
            printf("Updated list = ");
            display();
            break;

        case 6:
            deleteFromEnd();
            printf("Node is deleted from start \n");
            printf("Updated list = ");
            display();

        case 7:
            addInMid();

        case 8:
            addAtEnd(); */

        case 9:
            exit(1);

        default:
            printf("You have entered the wrong choice");
            break;
        }

        return 0;
    }
}