/*Name : Sundareshwaran J
Roll Number : 20UIT037
Program Name : Implementation of Linked List ADT
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void insertFirst(int input)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode -> data = input;
    newNode -> next = NULL;
    
    newNode -> next = start;
    start = newNode;
    
    printf("\nInserted Successfully");
}
void insertLast(int input)
{
    struct node * temp;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode -> data = input;
    newNode -> next = NULL;
    
    temp = start;
    while(temp ->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
    
    printf("\nInserted Successfully");
}

void insertAfter(int data, int element)
{
    int flag=0;
    struct node * newNode;
    struct node * temp;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    temp=start;
    while(temp->next!=NULL)
    {
        if(temp->data==element)
        {
            flag=1;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    if(temp->next==NULL && temp->data==element)
    {
        temp->next=newNode;
    }
    else if(flag=0)
    {
        printf("Element not found");
    }
    else
    {
        newNode->next=temp->next;
        temp->next=newNode;
    }  
}

void insertBefore(int data, int element)
{
    int flag=0;
    struct node * newNode;
    struct node * temp;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    temp=start;
    struct node * prev;
    if(start->data==element)
    {
        newNode->next = start;
        start=newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->data==element)
            {
                flag=1;
                break;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }

        if(temp -> data == element && temp -> next == NULL)
        {
            newNode -> next = prev -> next;
            prev -> next = newNode;
        }
        
        else if(flag==0)
        {
            printf("Element not found");
        }
        else 
        {
            newNode->next=prev->next;
            prev->next=newNode;
        }
    }
}

void insertPos(int input, int pos)
{
    int flag = 0;
    int index = 0;
    struct node * newNode;
    struct node * temp;
    newNode = malloc(sizeof(struct node));
    newNode ->data = input;
    newNode -> next = NULL;
    
    temp = start;
    while(temp -> next != NULL)
    {
        index+=1;
        if(index == pos-1)
        {
            flag =1;
            break;
        }
        else
        {
            temp = temp -> next;
        }
    }
    if(flag == 0)
        printf("Positon not Found.");
    else
    {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void deleteFirst()
{
    struct node * temp;
    temp = start;
    
    if(temp == NULL)
        printf("List is empty");
    else
    {
	    printf("Deleted Successfully");
	    start = start -> next;
    }
}

void deleteLast()
{
    struct node * temp;
    temp = start;
    
    if(temp == NULL)
        printf("List is empty");
    else
    {
    	struct node * prev;
    	while(temp -> next != NULL)
    	{
    		prev = temp;
    		temp = temp -> next;
    	}
    	prev -> next = NULL;
    	printf("Deleted Successfully");
    }
}

void deleteAfter(int element)
{
    if(start == NULL)
    {
        printf("LIST IS EMPTY..!");
    }
    else
    {
        int flag = 0;
    	struct node*temp=start;
    	struct node * after;
    	temp=start;
    	while(temp->next!=NULL)
    	{
    	    if(temp -> data == element)
    	    {
    	        flag = 1;
    	        break;
    	    }
    	    temp=temp->next;
    	}
    	if(flag == 0)
    	    printf("Element not Found");
    	else
       	{
        		after=temp->next;
    		    temp->next=after->next;
    		    printf("Deleted Successfully");
        }
    }
}

void deleteBefore(int element)
{
    if(start == NULL)
    {
        printf("LIST IS EMPTY..!");
    }
    else
    {
        int flag = 0;
        struct node * temp = start;
        struct node *prev;
        if(temp -> next -> data == element)
        {
            deleteFirst();
        }
        else
        {
            while(temp -> next != NULL)
            {
                if(temp-> next -> data == element)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    prev = temp;
                    temp = temp -> next;
                }
            }
            if(flag == 0)
            {
                printf("Element not Found");
            }
            else
            {
                prev -> next = temp -> next;
                printf("Deleted Successfully");
            }
        }
    }
}


void deletePos(int pos)
{ 
    if(start == NULL)
    {
        printf("LIST IS EMPTY..!");
    }
    else
    {
        int i=0,flag = 0;
        struct node * temp=start;
        struct node * prev;
        if(pos == 1)
        {
    	    start = start -> next;
    	    printf("Deleted Successfully");
        }
        else
        {
    
    	    while(temp->next!=NULL)
    	    {
    		
    		if(i==pos-1)
    		{
    		    flag =1;
    		    break;
    		}
    		else
    		{
    		    prev=temp;
    		    temp=temp->next;
    		    i++;
    		}
    	}
    	if(pos-1 == i)
    	{
    	  	prev -> next = NULL;
    	  	printf("Deleted Successfully");
        }
    	else if(flag == 0)
    	    printf("Element not found");
    	else
    	{
    	    prev->next = temp->next;
    	    printf("Deleted Successfully");
    	}
        }
    }
}


void search(int element)
{
    struct node * temp;
    temp = start;
    int flag = 0;
    while(temp != NULL)
    {
        if(temp -> data == element)
            flag = 1;
        temp = temp-> next;
    }
    if(flag == 0)
        printf("Element not found");
    else
        printf("Element found");
}
void display()
{
    struct node * temp;
    temp = start;
    
    if(temp == NULL)
        printf("List is empty");
    else
    {
        while(temp!= NULL)
        {
            printf("%d\n",temp-> data);
            temp = temp ->next;
        }
    }
}
void main()
{
    int choice,data,element;
    do
    {
        printf("\n   MENU\n   ----\n1. Insert First\n2. InsertLast\n3. Insert After\n4. Insert Before\n");
        printf("5. Insert at a Position\n6. Delete First\n7. Delete Last\n");
        printf("8. Delete after\n9. Delete Before\n10. Delete at a Position\n");
        printf("11. Search\n12. Display\n13. Exit\n\nEnter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("INSERT FIRST\nEnter the element : ");
                scanf("%d",&data);
                insertFirst(data);
                break;
            
            case 2:
                printf("INSERT LAST\nEnter the element : ");
                scanf("%d",&data);
                insertLast(data);
                break;
            
            case 3:
                printf("INSERT AFTER\nEnter the element : ");
                scanf("%d",&data);
                printf("Enter the element after it to be inserted : ");
                scanf("%d",&element);
                insertAfter(data,element);
                break;
                
            case 4:
                printf("INSERT BEFORE\nEnter the element : ");
                scanf("%d",&data);
                printf("Enter the element before it to be inserted : ");
                scanf("%d",&element);
                insertBefore(data,element);
                break;
                
            case 5:
                printf("INSERT AT A POSITION\nEnter the element : ");
                scanf("%d",&data);
                printf("Enter the Position it to be inserted : ");
                scanf("%d",&element);
                insertPos(data,element);
                break;
                
            case 6:
                deleteFirst();
                break;
                
            case 7:
                deleteLast();
                break;
               
            case 8:
                printf("Delete the element after? : ");
                scanf("%d",&element);
                deleteAfter(element);
                break;
                
            case 9:
                printf("Delete the element before? : ");
                scanf("%d",&element);
                deleteBefore(element);
                break;
                
            case 10:
                printf("Enter the Position it to be Delete : ");
                scanf("%d",&element);
                deletePos(element);
                break;
                
            case 11:
                printf("Enter the element to be searched : ");
                scanf("%d",&element);
                search(element);
                break;
                
            case 12:
                display();
                break;
                
            default:
                printf("INVALID CHOICE..!");
        }
    }while(choice!=13);
}






