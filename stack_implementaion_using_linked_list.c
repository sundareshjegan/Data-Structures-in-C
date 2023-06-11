/*  Name : Sundareshwaran J
    Roll number : 20UIT037
    Program Name : Implementation of Stack using Linked List
*/

//including the header files
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//defining the structure of the node
struct node
{
	int data;
	struct node * top;
};
struct node * start = NULL;

//function to push the element
void push(int input)
{
    struct node * temp;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode -> data = input;
    newNode -> top = NULL;
    
    if(start == NULL)
    {
	    start = newNode;
	    printf("\nPushed Successfully");
    }
    else
    {
	    temp = start;
	    while(temp ->top != NULL)
	    {
		    temp = temp -> top;
	    }
	    temp -> top = newNode;
	    printf("\nPushed Successfully");
     }
}

//function to pop an element
void pop()
{
    struct node * temp;
    temp = start;
    
    if(start == NULL)
        printf("Stack is empty");
    else if(start -> top == NULL)
	    start = NULL;
    else
    {
    	struct node * prev;
    	while(temp -> top != NULL)
    	{
    		prev = temp;
    		temp = temp -> top;
    	}
    	prev -> top = NULL;
    	printf("Popped Successfully");
    }
}

//function to search an element in stack
void search(int element)
{
    struct node * temp;
    temp = start;
    int flag = 0;
    while(temp != NULL)
    {
        if(temp -> data == element)
            flag = 1;
        temp = temp-> top;
    }
    if(flag == 0)
        printf("Element %d is not found in stack!",element);
    else
        printf("Element %d is found in stack.",element);
}

//function to check whether stack is empty or not
bool isEmpty()
{
	if(start == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//function to display the elements in stack
void display()
{
    struct node * temp;
    temp = start;
    
    if(temp == NULL)
        printf("Stack is empty");
    else
    {
        while(temp!= NULL)
        {
	        printf("%d -> ",temp -> data);
            temp = temp ->top;
        }
        printf("NULL");
    }
}

//main function
void main()
{
    int choice,data;        //variable declaration
    
    //do while loop to call the functions accordingly using switch case
    do
    {
        printf("\n     Menu\n     ----\n1. Push\n2. Pop\n3. Display\n");
        printf("4. Search\n5. Is-Empty\n6. Exit\n");
        printf("Enter your choice : ");
        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("  PUSH\n  ----\nEnter the value to push : ");
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
                    printf("Stack is not Empty...\nElements in stack are : ");
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


