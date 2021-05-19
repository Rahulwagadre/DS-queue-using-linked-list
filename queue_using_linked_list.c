#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Initialization of node
typedef struct Node{
int data;
struct Node *next;
}Node;

// Initialization of rear and front of queue
Node *rear=NULL,*front=NULL;

// Function for creating new node
Node* create_node(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Check for underflow condition
bool is_empty()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty...!\n\n");
        return true;
    }
    else{
        printf("Queue is not empty...!\n\n");
        return false;
    }
}

// Enqueue function for insertion
void enqueue(int data)
{
    Node *temp = create_node(data);
    if(front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = rear->next;
    }
}

// Dequeue function for deletion
int dequeue()
{
    Node *temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is already empty...!\n\n");
        return 0;
    }
    else if(front == rear)
    {
        int res = front->data;
        front = NULL;
        rear = NULL;
        return res;
    }
    else{
        int res = front->data;
        front = front->next;
        free(temp);
        return res;
    }
}

// get front element
int get_front()
{
    return front->data;
}

// Print queue
void show_queue()
{
    Node *ptr = front;
    printf("\n\n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function
int main()
{
    /*enqueue(10);
    enqueue(9);
    enqueue(8);
    enqueue(7);
    show_queue();
    dequeue();
    show_queue();
    printf("%d\n",get_front());
    is_empty();*/

    printf("****   Queue implementation using linked list   ****\n");
    do{
        int choice,data;
        printf("\n\n_______________________________________________________________________________\n\n\n\n");
        printf("-> enqueue : press 1\n-> dequeue : press 2\n-> get front element : press 3\n-> checking for underflow : press 4\n-> show queue : press 5\n-> To end programm : press 6\n");
        printf("\n\nenter choice > ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n\nEnter data > ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2: printf("\n\nelement deleted > %d",dequeue());
                    break;
            case 3: printf("\n\nfront element > %d",get_front());
                    break;
            case 4: is_empty();
                    break;
            case 5: show_queue();
                    break;
            case 6: printf("\n\nprogram terminated successfully !\n\n");
                    printf("_______________________________________________________________________________\n\n\n");
                    exit(0);
            default: printf("\n\noops...! wrong input");

        }
    }while(1);
    return 0;
}
