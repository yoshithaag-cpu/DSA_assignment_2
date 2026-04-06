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