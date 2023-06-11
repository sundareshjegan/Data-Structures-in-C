/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Bubble sort
*/

#include<stdlib.h>
#include<stdio.h>

//function to create an list
void *createList(int limit)
{
	int i;
	int *list = malloc(sizeof(int)*limit);	
	if(limit<=0)
	{
		printf("Sorry..!Invalid Input");
		createList(limit);
	}
	else
	{
		for(i=0;i<limit;i++)
		{
			printf("Enter the array element %d : ",i+1);
			scanf("%d",&list[i]);
		}
	}
	return list;
}

//function to display the elements in the list
void display(int arr[],int limit)
{
	int i;
	if(limit<=0)
	{
		printf("Sorry Invalid Limit..!");
	}
	else
	{
		printf("[ ");
		for(i=0;i<limit-1;i++)
		{
			printf("%d, ",arr[i]);
		}
		printf("%d ]",arr[i]);
	}		
}

//main function
void main()
{
	printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Bubble sort\n\n\n");
	
	int i,j,limit,temp;             //variable declaration
	printf("Enter the total number of elements in list : ");
	scanf("%d",&limit);
	int *arr = createList(limit);
	
	printf("\nBefore sorting : ");
	display(arr,limit);
	
	//sorting of the list using Bubble sort method
	for(i=0;i<limit-1;i++)
	{
		for(j=0;j<limit-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
			    //swap arr[j] and arr[j+1]
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\nAfter sorting  : ");
	display(arr,limit);
}

	





