/*  Name : Sundareshwaran J
    Roll Number : 20UIT037
    Program Name : Implementation of Josephus Problem using Circular Linked List
*/

#include<stdio.h>
#include<stdlib.h>

// Define a struct node
struct node
{
    int data;
    struct node * next;
};

//main function
void main()
{
    //variable declaration
    int i,j,n,k;        
    struct node *temp,*start,*prev,*newnode;
    
    printf("Enter the total number of persons : ");
    scanf("%d",&n);
    if(n<=0)
        printf("Invalid Input");
    else
    {
        printf("Enter the number of persons to be skipped : ");
        scanf("%d",&k);
        
        start = malloc(sizeof(struct node));
        start -> data = 1;
        temp = start;
        
        for(i=2;i<=n;i++)
        {
            newnode = malloc(sizeof(struct node));
            temp -> next = newnode;
            newnode -> data = i;
            newnode -> next = start;
            temp = newnode;
        }
        for(j=0;j<=n-1;j++)
        {
            for(i=0;i<=k-1;i++)
            {
                prev = temp;
                temp = temp -> next;
            }
            prev -> next = temp -> next;
        }
        printf("The winner is : %d",temp-> data);
    }
}


