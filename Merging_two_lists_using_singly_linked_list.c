/*  Name : Sundareshwaran J
    Roll Number : 20UIT037
    Program Name : Implementation of Merging of two list using Singly Linked List
*/

#include<stdio.h>
#include<stdlib.h>

// Define a struct node
struct node
{
    int data;
    struct node * next;
};

// Insert the list elements to a singly linked list
void insertLast(struct node **h, int val)
{
    //create a new node
    struct node * newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    struct node * temp=*h;
    if(*h==NULL)
    {
        *h=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next=newnode;
    }
    //if head is NULL, it is an empty list
    
    //Otherwise, find the last node and add the newNode
}
// Merge the two list
void merge(struct node * h1, struct node * h2)
{
    // Traverse the first node;
    struct node * temp=h1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    // Insert the second list at the end of the first linked list
    temp->next=h2;
}
// Display the linked list
void display(struct node * h)
{
    if(h==NULL)
        printf("Sorry.... Empty List");
    else
    {
        struct node * temp=h;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL \n");
    }
}

// Main Function
void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n1, n2, ip,i;
    
    // Get the limit for the list 1
    printf("Enter the limit for list-1: \n");
    scanf("%d",&n1);
    // Generate the loop and get the input from the user. Call the create function by passing the &head1 and input
    printf("Enter the elements: \n");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&ip);
        insertLast(&head1,ip);
    }
    // Call the display function to display the list
    display(head1);
    
    // Get the limit for the list 2
    printf("Enter the limit for list-2: \n");
    scanf("%d",&n2);
    // Generate the loop and get the input from the user. Call the create function by passing the &head2 and input
    printf("Enter the elements: \n");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&ip);
        insertLast(&head2,ip);
    }
    // Call the display function to display the list
    display(head2);
    // Call the merge function by passing the necessary parameters
    merge(head1,head2);
    // Call the display function to display the merged list
    printf("The merged list is : ");
    display(head1);
}

