/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of AVL Tree - Insertion
*/


#include <stdio.h>
#include <stdlib.h>

// Define a node
struct node {

	int data;
	struct node *left;
	struct node *right;
  	int height;
};


// Calculate height
int getHeight(struct node *temp) {
	// Check if temp is NULL, if yes return 0 else return the height
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		return temp->height;
	}
  
}

int max(int a, int b){
	// Check if the value of a is greater than b. If yes, return a else return b
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
	
}

int getBalanceFactor(struct node *temp) {
  // Check if temp is NULL, if yes return 0 else return the difference of height(temp->left) and height(temp->right) using getHeight function
  	if(temp == NULL)
  	{
  		return 0;
  	}
  	else
  	{
  		return (getHeight(temp->left) - getHeight(temp-> right));
  	}
}

// Create a node
struct node *newNode(int value) {
  
  	struct node *newnode;
  	newnode = malloc(sizeof(struct node));
  	
  	newnode -> data = value;
  	newnode -> left = NULL;
  	newnode -> right = NULL;
  	
  	return (newnode);
}

// Right rotate
struct node *rightRotate(struct node *y) {
  struct node *x = y->left;
  struct node *t = x->right;

  x->right = y;
  y->left = t;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

  return x;
}

// Left rotate
struct node *leftRotate(struct node *x) {
  struct node *y = x->right;
  struct node *t = y->left;

  y->left = x;
  x->right = t;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}


// Insert node
struct node *insertNode(struct node *temp, int value) {
  // Check if the temp is NULL. If yes, return function call of newNode(value)
  if(temp == NULL)
  {
  	return newNode(value);
  }
  
   // Check if the value is less than temp->data. If yes, assign the function of insertNode(temp->left, value) to temp->left
  else if(value < temp->data)
  {
  	temp->left = insertNode(temp->left,value);
  }
  
  // Elseif check the value is greater than temp->data. If yes, assign the function of insertNode(temp->right, value) to temp->rght
  else if(value>temp-> data)
  {
  	temp->right = insertNode(temp->right,value);
  } 
  // else return the node temp
  else
  {
  	return temp;
  }
  
  
  // Compute the height
  temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));

  // Compute the balance factor. Call the getBalanceFactor(temp) and store it in an integer named balance
  int balance = getBalanceFactor(temp);
  
  // If the balance is greater than 1 and value is less than temp->left->value, return the function call rightRotate(temp)
  if(balance > 1 && value < temp->left-> data)
  {
  	return rightRotate(temp);
  }
  
  // If the balance is less than -1 and value is greater than temp->right->value, return the function call leftRotate(temp)
  else if(balance <-1 && value > temp->right->data)
  {
  	return leftRotate(temp);
  }

 // If the balance is greater than 1 and value is greater than temp->left->value, assign function call leftRotate(temp->left) to temp->left then return the function call rightRotate(temp)
 	else if(balance >1 && value > temp->left->data)
 	{
 		temp-> left = leftRotate(temp->left);
 		return rightRotate(temp);
	}
 
 // If the balance is less than -1 and value is greater than temp->rught->value, assign function call rightRotate(temp->right) to temp->tight then return the function call leftRotate(temp)
  
  	else if(balance < -1 && value > temp-> right-> data)
  	{
  		temp-> right = rightRotate(temp->right);
  		return leftRotate(temp);
  	}
 // Finally return the node temp.
 	return temp;
  
}


// Display the values

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }

}

int main() 
{

	printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of AVL Tree - Insertion\n\n");
  	struct node *root = NULL;
	int no_of_nodes,i,element;
	
  // Get the number of nodes
  printf("Enter the total number of nodes : ");
  scanf("%d",&no_of_nodes);
  
  // Generate a loop, get the element from the user and pass the root & element in insertNode function, Store the return value in root.
  for(i=1;i<=no_of_nodes;i++)
  {
  	printf("Enter the element %d : ",i);
  	scanf("%d",&element);
  	root = insertNode(root,element);
  }
  // Call the inorder by passing the root.
  printf("The elements are : \n");
  inorder(root);
  return 0;
}

