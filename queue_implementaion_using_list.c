/* 
Name : Sundareshwaran J
Roll Number : 20UIT037
Program Name : Implementation of Queue using Array
*/

#include<stdio.h>               //header file
#include<stdbool.h>

//global variables declaration
int rear = -1,front = 0;
int Queue[100],size;


//function to check whether Queue is empty or not
bool isEmpty()
{
    if(rear < front)
        return true;
    else
        return false;
}

//function to check whether the Queue is full
bool isFull()
{
    if(rear == size-1)
        return true;
    else
        return false;
}

//function to create Queue
void create_queue()
{
    printf("Enter the limit of Queue : ");
    scanf("%d",&size);
    if(size<=0)
    {
        printf("Invalid Input... Size must greater than 0");
        create_queue();
    }
}

//function to enqueue a value into Queue
void enqueue(int data)
{
    if(isFull())
    {
        printf("Queue is Full");
    }
    else
    {
	rear = rear + 1;
        Queue[rear] = data;
    }
}

//function to dequeue(delete an element from Queue)
void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty");
    }
    else
        front = front + 1;
}

//function to search an element in Queue
void search(int data)
{
    int i,flag = 0;
    if(isEmpty())
        printf("Queue is empty");
    else
    {
        for(i=front;i<=rear;i++)
        {
            if(Queue[i]==data)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            printf("%d is present in Queue.",data);
        else
            printf("%d is not present in Queue.",data);
    }
}

//function to display the elements in the Queue
void display()
{
    int i;
    if(isEmpty())
        printf("Queue is empty");
    else
    {
        printf("The elements in Queue are : \n");
        for(i=rear;i>=front;i--)
        {
            printf("| %d |\n",Queue[i]);
        }
    }
}
//Main function
int main()
{
    int choice,data;
    create_queue();         //function call
    
    //do while loop to call the functions accordingly using switch case
    do
    {
        printf("\n     Menu\n     ----\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("4. Search\n5. Is-Empty\n6. Is-Full\n7. Exit\n");
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
                if(isFull())
                    printf("Queue is Full");
                else
                    display();
                break;
                
            case 7:
                printf("Bye...");
                break;
                
            default:
                printf("Invalid choice..!");
        }
    }while(choice!=7);
}



