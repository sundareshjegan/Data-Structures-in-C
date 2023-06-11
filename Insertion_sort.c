/*Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of insertion sort
*/

//including header file
#include<stdlib.h>
#include<stdio.h>

//function to create a array
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

//function to display the elements in the array
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

//main function to perform insertion sort
void main()
{
	printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Insertion sort\n\n\n");
	
	int limit,i,j,key;
	
	printf("Enter the total number of elements in the list : ");
	scanf("%d",&limit);
	
	int *list = createList(limit);
	
	printf("\nBefore sorting : ");
	display(list,limit);
	
	//loop to sort the elements in the given list
	for(i=1;i<limit;i++)
	{
		key = list[i];
		j = i-1;
		while(j>=0 && list[j] > key)
		{
			list[j+1] = list[j];
			j-=1;
		}
		list[j+1] = key;
	}
	printf("\nAfter sorting  : ");
	display(list,limit);
}
	
	


