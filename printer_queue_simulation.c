// ALGORITHM
// - Start the program.
// - Initialize front and rear as NULL.
// - For Enqueue:
//     Create a new node
//     If queue is empty → set front = rear
//     Else → add node at rear and move rear
// - For Dequeue:
//     If queue is empty → show underflow
//     Else → remove node from front and move front
// - For Display:
//     Traverse from front to rear
//     Print all elements
// - End the program.

#include<stdio.h>
#include<stdlib.h>

// node represents each document in queue
struct node
{
    int data;               
    struct node *next;      
};

struct node *front=NULL;   // front = where we delete
struct node *rear=NULL;    // rear = where we insert

// add a document to queue
void enqueue()
{
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));  // create new node

    printf("Enter the value:");
    scanf("%d",&temp->data);

    temp->next=NULL;   // new node will be last

    if(rear==NULL)     // if queue is empty
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;  // link at end
        rear=temp;        // move rear
    }

    printf("Document entered successfully!!");
}

// remove a document from queue
void dequeue()
{
    if(front==NULL)     // empty queue
    {
        printf("Underflow!!!");
    }
    else
    {
        struct node *temp=front;  
        front=front->next;        // move front
        free(temp);               // delete node
    }

    if(front==NULL)               // if queue becomes empty
    {
        rear=NULL;
    }

    printf("Document deleted successfully!!");
}

// display all documents
void display()
{
    if(front==NULL)   // nothing to show
    {
        printf("Queue empty!!");
    }
    else
    {
        struct node *temp=front;

        while(temp!=NULL)
        {
            printf("%d<->",temp->data);  // print each node
            temp=temp->next;
        }
    }
}

int main()
{
    int choice;              
    
    printf("1.-->Enqueue function\n 2.-->Dequeue function\n 3.-->Display function\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            enqueue();       
            break;

        case 2:
            dequeue();       
            break;

        case 3:
            display();       
            break;

        default:
            break;
    }
    
    return 0;
}

// Input:
// 1.-->Enqueue function
// 2.-->Dequeue function
// 3.-->Display function

// Enter your choice: 1
// Enter the value: 10

// Output:
// Document entered successfully!!

// Input:
// Enter your choice: 3

// Output:
// 10<->

// Input:
// Enter your choice: 2

// Output:
// Document deleted successfully!!
