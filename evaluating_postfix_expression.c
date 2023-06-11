/*
Name : Sundareshwaran J
Roll Number : 20UIT037
Program Name : Implementation of Evaluating a Postfix Expression
*/

//including the header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//defining the structure of the node
struct node
{
	int data;
	struct node * top;
};
struct node * start = NULL;

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
    }
    else
    {
	    temp = start;
	    while(temp ->top != NULL)
	    {
		    temp = temp -> top;
	    }
	    temp -> top = newNode;
     }
}

//function to pop an element
int pop()
{
    struct node * temp;
    temp = start;
	int popped_element;
    
    if(start -> top == NULL)
	{
		popped_element = start->data;
		start = NULL;
	}
    else
    {
    	struct node * prev;
    	while(temp -> top != NULL)
    	{
    		prev = temp;
    		temp = temp -> top;
    	}
		popped_element = temp->data;
    	prev -> top = NULL;
    	
    }
	printf("Popped out element is %d\n",popped_element);
	return popped_element;
}

void display()
{
    struct node * temp;
    temp = start;
    
    if(temp == NULL)
        printf("Stack is empty");
    else
    {
		printf("The elements are\n");
        while(temp!= NULL)
        {
	        printf("%d -> ",temp -> data);
            temp = temp ->top;
        }
    }printf("\n");
}

void main()
{
	char exp[50];
	int i,first_popped,second_popped;
	
	printf("Enter the expression : ");
	scanf("%s",exp);
	
	for(i=0;i<strlen(exp);i++)
	{
		if(isdigit(exp[i]))
		{
			push(exp[i]-'0');
			display();
		}
		else
		{
			first_popped = pop();
			second_popped = pop();
	
			switch(exp[i])
			{
				case '+' :
					push(second_popped + first_popped);
					display();
					break;
		
				case '-':
					push(second_popped - first_popped);
					display();
					break;

				case '*':
					push(second_popped * first_popped);
					display();
					break;

				case '/':
					push(second_popped / first_popped);
					display();
					break;
			}
		}
	}printf("\n\nThe value for the %s postfix expresiion is %d.",exp,pop());
}
