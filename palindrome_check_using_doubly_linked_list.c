/*
Name : Sundareshwaran J
Roll Number : 20UIT037
Program Name : Check for Palindrome String using Doubly Linked List
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the struct node
struct node
{
    char data;
    struct node * next, *prev;
};
// Insert the characters in the work to a doubly linked list

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
        newnode->prev=temp;
    }
    //if head is NULL, it is an empty list
    
    //Otherwise, find the last node and add the newNode

}

// Check for Palindrome using left and right struct pointer

int palindrome(struct node *h)
{
    struct node *right = h;
    struct node *left = h;
    int flag = 0;
    
    // Move the right struct pointer to the last node
    while(right->next!=NULL)
    {
        right=right->next;
    }
    // Move the left struct pointer and check is the data pointed by left and right are not same. If true, set the flag as 1 and break. Move the left and right pointer correspondingly
    while(left->next!=NULL)
    {
        if(left->data!=right->data)
        {
            flag=1;
            break;
        }
        else
        {
            left=left->next;
            right=right->prev;
        }
    }
    // return the flag variable
}

// Display the doubly linked list

void display(struct node *h)
{
    if(h==NULL)
    {
        printf("Sorry.... Empty List");
    }
    else
    {
        struct node * temp=h;
        printf("NULL ->");
        while(temp!=NULL)
        {
            printf(" %c ->",temp->data);
            temp=temp->next;
        }
        printf("NULL \n");
    
    }
}

// Main function

void main()
{

    struct node *head1 = NULL;
    char name[50];
    int i;
    //Get the input value
    printf("Enter a string : ");
    scanf("%s",name);
    
    // Generate a loop for length of the string and call the insertLast function by passing &head1 and input characters
    for(i=0;i<strlen(name);i++)
    {
        insertLast(&head1,name[i]);
    }
    
    // Call the display function by passing the head1
    display(head1);
    // Declare a resultant variable and call the palindrome function by passing head1
    // if the resultant variable is 0 the display palindrome else display not palindrome
    if(palindrome(head1)==0)
    {
        printf("%s is a palindrome",name);
    }
    else
    {
        printf("%s is not a palindrome",name);
    }
}

