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
    //Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data");
    scanf( "%d", newNode->data);
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

void deleteFromStart()
{
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    else
    {
        if (head != tail)
        {
            head = head->next;
        }
        //If the list contains only one node
        //then, it will remove it and both head and tail will point to NULL
        else
        {
            head = tail = NULL;
        }
    }
}

void deleteFromMid() {  
    struct node *temp, *current;  
      
    //Checks if list is empty  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    else {  
        //Store the mid position of the list  
        int count = (size % 2 == 0) ? (size/2) : ((size+1)/2);  
          
        //Checks whether the head is equal to the tail or not, if yes then the list has only one node.  
        if( head != tail ) {  
            //Initially, temp will point to head  
            temp = head;  
            current = NULL;  
              
            //Current will point to node previous to temp  
            //If temp is pointing to node 2 then current will point to node 1.  
            for(int i = 0; i < count-1; i++){  
                current = temp;  
                temp = temp->next;  
            }                  
            if(current != NULL) {  
                //temp is the middle that needs to be removed.  
                //So, current node will point to node next to temp by skipping temp.  
                current->next = temp->next;  
                //Delete temp  
                temp = NULL;  
            }  
            //If current points to NULL then, head and tail will point to node next to temp.  
            else {  
                head = tail = temp->next;  
                //Delete temp  
                temp = NULL;  
            }      
        }  
        //If the list contains only one element   
        //then it will remove it and both head and tail will point to NULL  
        else {  
            head = tail = NULL;  
        }  
    }  
    size--;  
}  
      
void deleteFromEnd() {  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    else {  
        //Checks whether the list contains only one element  
        if(head != tail ) {  
            struct node *current = head;  
            //Loop through the list till the second last element such that current.next is pointing to tail  
            while(current->next != tail) {  
                current = current->next;  
            }  
            //Second last element will become new tail of the list  
            tail = current;  
            tail->next = NULL;  
        }  
        //If the list contains only one element   
        //Then it will remove it and both head and tail will point to NULL  
        else {  
            head = tail = NULL;  
        }  
    }  
}  

void addInMid(){  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    printf("Enter data");
    scanf( "%d", newNode->data);
    newNode->next = NULL;
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail would point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        struct node *temp, *current;  
        //Store the mid position of the list  
        int count = (size % 2 == 0) ? (size/2) : ((size+1)/2);  
        //Node temp will point to head  
        temp = head;  
        current = NULL;  
   
        //Traverse through the list till the middle of the list is reached  
        for(int i = 0; i < count; i++) {  
            //Node current will point to temp  
            current = temp;  
            //Node temp will point to node next to it.  
            temp = temp->next;  
        }  
          
        //current will point to new node  
        current->next = newNode;  
        //new node will point to temp  
        newNode->next = temp;  
    }  
    size++;  
}  

void addAtEnd() {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    printf("Enter data");
    scanf( "%d", newNode->data);
    newNode->next = NULL;
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}  

//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  

//countNodes() will count the nodes present in the list
int countNodes()
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
    return count;
}

void main()
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
                break;
    
            case 2:
                countNodes();
                break;
    
            case 3:
                addNode();
                break;
    
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
                addAtEnd();
    
            case 9:
                exit(1);
    
            default:
                printf("You have entered the wrong choice");
        }
    }
}