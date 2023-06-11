/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Open Hashing Algorithm
*/

#include<stdio.h>
#include<stdlib.h>

// Define a node with one integer variable and a struct node * variable
struct node
{
    int data;
    struct node *next;
};

// Declare the one dimensional struct node * variable
struct node *chain[20];


// Define an init function
void init(int size)
{
	int i;
    // Generate a loop from 0 to size
    for(i=0;i<size;i++)
    // Assign NULL to chain[i]
	{
		chain[i]=NULL;
	}		
}

// Define an insert function
void insert(int value)
{
	int size;
    //Create a newnode with value
	struct node*newnode = malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;
    
    //Calculate hash key
	int key=value % size;
    
    //Check if chain[key] is empty. If so, assign newNode to chain[key]
	if(chain[key]==NULL)
	{
		chain[key]=newnode;
	}
    //else
	else
        
        //add the node at the end of chain[key].
	{
        	struct node *temp = chain[key];
       
		
        // Traverse untill end
		while(temp->next)
		{
			temp=temp->next;
		}
		// Assign newNode to temp->next

	       		 temp->next=newnode;	
	}	
	    
}

// Display the list
void print(int size)
{
	int i;
    // Generate an outer loop from 0 to size
	    for(i=0;i<size;i++)
    // Declare struct node *temp = chain[i];
	{
		struct node *temp = chain[i];
		printf("chain[%d]-->",i);
    // Traverse the list to display the elements
		while(temp)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
    /*
        Display should be in this format
        
        chain[0]-->7 -->0 -->NULL
        chain[1]-->NULL
    */
		printf("NULL\n");
	}	
}

int main()
{
    printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Open Hashing Algorithm\n\n");
    // Declare the necessary variables
	int size,ele,i;
    // Get the size from the user
	printf("Enter the Size : ");
	scanf("%d",&size);
    // Call the init function by passing size
	init(size);
    // Generate a loop from 0 to size.
	for(i=0;i<size;i++)
        // Get the input element from the user and call the insert function by passing the element.
	{	
		printf("Enter the Element : ");
		scanf("%d",&ele);
		insert(ele);
    // Call the print function by passing size
	}
	print(size);
    return 0;
}


