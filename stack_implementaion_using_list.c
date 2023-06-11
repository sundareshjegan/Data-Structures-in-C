/* 
Name : Sundareshwaran J
Roll Number : 20UIT037
Program Name : Implementation of Stack using Array
*/

#include<stdio.h>               //header file
#include<stdbool.h>

//global variables declaration
int top = -1;
int stack[100],size;


//function to check whether stack is empty or not
bool isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

//function to check whether the stack is full
bool isFull()
{
    if(top == size-1)
        return true;
    else
        return false;
}

//function to create stack
void create_stack()
{
    printf("Enter the limit of stack : ");
    scanf("%d",&size);
    if(size<=0)
    {
        printf("Invalid Input... Size must greater than 0");
        create_stack();
    }
}

//function to push a value into stack
void push(int data)
{
    if(isFull())
    {
        printf("Stack is Full");
    }
    else
    {
        top = top + 1;
        stack[top] = data;
    }
}

//function to pop(delete an element from stack)
void pop()
{
    if(isEmpty())
    {
        printf("Stack is empty");
    }
    else
        top -= 1;
}

//function to search an element in stack
void search(int data)
{
    int i,flag = 0;
    if(isEmpty())
        printf("Stack is empty");
    else
    {
        for(i=0;i<=top;i++)
        {
            if(stack[i]==data)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            printf("%d is present in stack.",data);
        else
            printf("%d is not present in stack.",data);
    }
}

//function to display the elements in the stack
void display()
{
    if(isEmpty()==1)
        printf("Stack is empty");
    else
    {
        printf("The elements in stack are : \n");
        for(int i=top;i>=0;i--)
        {
            printf("| %d |\n",stack[i]);
            printf(" --- \n");
        }
    }
}
//Main function
int main()
{
    int choice,data;
    create_stack();         //function call
    
    //do while loop to call the functions accordingly using switch case
    do
    {
        printf("\n     Menu\n     ----\n1. Push\n2. Pop\n3. Display\n");
        printf("4. Search\n5. Is-Empty\n6. Is-Full\n7. Exit\n");
        printf("Enter your choice : \n");
        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("PUSH\n----\nEnter the value to push : ");
                scanf("%d",&data);
                push(data);
                break;
            
            case 2:
                pop();
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
                    printf("Stack is Empty");
                else
                    printf("You can push upto %d elements.",(size - top-1));
                break;
                
            case 6:
                if(isFull())
                    printf("Stack is Full");
                else
                    printf("You can push upto %d elements.",(size - top-1));
                break;
                
            case 7:
                printf("Bye...");
                break;
                
            default:
                printf("Invalid choice..!");
        }
    }while(choice!=7);
}


