/*
Name: Sundareshwaran. J
Roll Number:20UIT037
Program Name: Implementation of Deque
*/

#include<stdio.h>

//Declare the array and size

int queue[25];
int rear=-1;
int front=-1;
int n,input;
void create()
{
    printf("\n\nEnter the size of queue: ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("\nInvalid Input\n");
        create();
    }
}
void enqueue_rear(int input){
    // Overflow Condition
    if( (front == 0 && rear == n-1) || (front == rear+1) )
    {
        printf("It is Overflow");
    }
    else
    {
        // Insert the value through rear end
        if(rear == n-1)
            rear=0;
        else if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
        queue[rear]=input;
    }
}

void enqueue_front(int input){
     // Overflow Condition
    if( (front == 0 && rear == n-1) || (front == rear+1) )
    {
         printf("Deque Overflown..!");
    }
    else{
        // Insert the value through front end
        if(front == 0)
            front = n-1;
            
        else if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            front = front-1;
        }
            queue[front]=input;
    }
}

void dequeue_rear()
{
    if(front==-1)
        printf("Deque underflown..!");
    else
        rear--;
}

void dequeue_front()
{
    if(front==-1)
        printf("Deque underflown..!");
    else
    {
        if(front==n-1)
        {
            front=0;
        }
        else
            front++;
    }    
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("\nDeque is Empty\n");
    }
 
    if(front <= rear)
    {
// Generate a loop front to rear and display the elements using front end
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
    else
    {
        // Generate a loop from front to n-1 and display the elements using front end
        for(i=0;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
        for(i=front;i<=n-1;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}

void main()
{
    printf("Name : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Deque");
    int choice;
    int input;
    create();
    do
    {
        printf("\n\tMenu\n\t----\n1. Enqueue_Rear\n2. Enqueue_front\n3. Dequeue_rear\n4. Dequeue_front\n5. Display\n6. Exit");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&input);
                enqueue_rear(input);
                break;
                
            case 2:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&input);
                enqueue_front(input);
                break;
                
            case 3:
                dequeue_rear();
                break;
                
            case 4:
                dequeue_front();
                break;
                
            case 5:
                display();
                break;
                
            case 6:
                printf("Bye..!");
                break;
                
            default:
                printf("Invalid choice..!");
                break;
        }
    }while(choice!=6);
}

