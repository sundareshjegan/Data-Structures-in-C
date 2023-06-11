/* 
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Searching Algorithms
*/

#include<stdio.h>			//include header file

int list[30];
int i,j,total;
void create_list()
{
	printf("Enter the total number of elements in the list : ");
	scanf("%d",&total);
	
	if(total<=0)
	{
		printf("Sorry invalid input.");
		create_list();
	}
	else
	{
		printf("\n");
	
		for(i=0;i<total;i++)
		{
			printf("Enter the element %d : ",i+1);
			scanf("%d",&list[i]);
		}
	}
}
void linear_search()
{
    int search;
    printf("Enter the element to be searched : ");
	scanf("%d",&search);
	
	int flag = 0;	
	for(i=0;i<total;i++)
	{
		if(search == list[i])
		{
		    flag = 1;
			printf("Element %d is present in the list at position %d.",search,i+1);
			break;
		}
	}
	if(flag == 0)
		printf("Element %d is not found.",search);
}
void binary_search()
{
	int low = 0, high = total-1,mid,flag = 0,element;
	for(i=0;i<total-1;i++)
	{
		for(j=i-1;j<total-i-1;j++)
		{
		    if(list[j]>list[j+1])
		    {
		    	int temp = list[j];
			    list[j] = list[j+1];
			    list[j+1] = temp;
		    }
		}
	}
	
	printf("Enter the element to be searched : ");
	scanf("%d",&element);
	for(i=low;i<=high;i++)
	{
	    mid = (low+high)/2;
	    if(list[mid]==element)
	    {
	        printf("Element %d is found at position %d.",element,mid+1);
            flag = 1;
            break;
	    }
	    else if(list[mid]<element)
	    {
	        low = mid+1;
	    }
	    else if(list[mid]>element)
	    {
	        high = mid-1;
	    }
	}
	if(flag == 0)
	{
	    printf("The element %d is not found in the list.",element);
	}
	
}
void main()
{
    create_list();
	int choice,element;
	do
	{
		printf("\n\nMENU\n====\n1. Linear Search\n2. Binary Search\n3. Exit\nEnter the choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				linear_search();
				break;
			
			case 2:
				binary_search();
				break;
				
			case 3:
				printf("Bye..!\n");
				break;
			
			default:
				printf("Invalid choice..!");
				break;
		}
	}while(choice!=3);
}

