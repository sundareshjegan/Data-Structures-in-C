/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Queue using Linked List
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//defining the structure of the node
struct node
{
	int data;
	struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;

//function to check the queue is empty or not
int isEmpty()
{
	if(front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(int input)
{
    struct node * temp;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode -> data = input;
    newNode -> next = NULL;
    
    if(rear == NULL && front == NULL)
    {
	    rear = newNode;
	    front = newNode;
    }
    else
    {
	    rear->next = newNode;
	    rear = rear-> next;
     }
}

void dequeue()
{
    struct node * temp;
    temp = front;
    
    if(temp == NULL)
        printf("Queue is empty");
    else
    {
	    front = front -> next;
    }
}

void search(int element)
{
    struct node * temp;
    temp = front;
    int flag = 0;
    while(temp != NULL)
    {
        if(temp -> data == element)
            flag = 1;
        temp = temp-> next;
    }
    if(flag == 0)
        printf("Element %d is not found in queue!",element);
    else
        printf("Element %d is found in queue.",element);
}

void display()
{
    struct node * temp;
    temp = front;
    
    if(temp == NULL && rear == NULL)
        printf("queue is empty");
    else
    {
	printf("The elements in the Queue are : \n");
        while(temp!= NULL)
        {
	    printf("%d -> ",temp -> data);
            temp = temp ->next;
        }
        printf("NULL");
    }
}

void main()
{
    int choice,data;
    
    //do while loop to call the functions accordingly using switch case
    do
    {
        printf("\n     Menu\n     ----\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("4. Search\n5. Is-Empty\n6. Exit\n");
        printf("Enter your choice : \n");
        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("  ENQUEUE\n  ----\nEnter the value to Enqueue : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
            
            case 4:
                printf("Enter the element to be searched : ");
                scanf("%d",&data);
                search(data);
                break;
                
            case 5:
                if(isEmpty())
                    printf("Queue is Empty");
                else
                    display();
                break;

                
            case 6:
                printf("Bye...");
                break;
                
            default:
                printf("Invalid choice..!");
        }
    }while(choice!=6);
}


