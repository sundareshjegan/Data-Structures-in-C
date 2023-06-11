/* 
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Binary Search Tree
*/

#include<stdlib.h>
#include<stdio.h>

//defenition of a node
struct node
{
    int data;
    struct node *left,*right;
};

//function to create a node
struct node *create(int input)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    
    newnode-> data = input;
    newnode-> left = NULL;
    newnode-> right = NULL;
    
    return newnode;
}

//function to display the elements in the binary search tree using inorder traversal
void inorder(struct node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\n",node->data);
        inorder(node->right);
    }

}

//function to insert an element into the tree
struct node *insert(struct node *node, int input)
{
    if(node==NULL)
    {
        node = create(input);
    }
    else if(input<node->data)			//check whether inserting element is less than the present node
    {
        node -> left = insert(node->left,input);
    }
    else if(input>node->data)			//check whether inserting element is less than the present node
    {
        node-> right = insert(node->right,input);
    }
    return node;
}

struct node *search(struct node *node, int element)
{
    if(node == NULL || node-> data == element)
    {
        return node;
    }
    else if(element < node-> data)			//check whether searching element is less than the present node
    {
        return search(node-> left,element);
    }
    else if(element>node->data)				//check whether searching element is less than the present node
    {
        return search(node-> right,element);
    }
    return node;
}

void main()						//main function
{
    struct node *node = NULL;
    int num_nodes,choice,element;

	printf("Name : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of binary search tree\n\n");
    printf("Enter the root node value: ");
    scanf("%d",&element);
    node = insert(node,element);
    
    
   	do
   	{
   		printf("\n\n\tBINARY SEARCH TREE\n\t------ ------ ----\nCHOICES\n-------\n1. Insertion\n2. Display\n3. Search\n4. Exit\n\nEnter your choice : ");
   		scanf("%d",&choice);
   		
   		//switch case to perform insertion, display, search
   		switch(choice)
   		{
   			case 1:
   				printf("Enter the element to be inserted : ");
   				scanf("%d",&element);
   				create(element);
   				insert(node,element);
   				break;
   			
   			case 2:
   				printf("The elements in the binary search tree are : \n");
   				inorder(node);
   				break;
   			
   			case 3:
   				printf("Enter the element to be searched : ");
   				scanf("%d",&element);
   				
   				if(search(node,element)==NULL)
					printf("Element not found");
				else
					printf("Element found");
					
   				break;
   				
   			case 4:
   				printf("\nBye...!\n");
   				break;
   			
   			default:
   				printf("Invalid choice...");
   				break;
   				
   		}
   	}while(choice!=4);
}
   				


