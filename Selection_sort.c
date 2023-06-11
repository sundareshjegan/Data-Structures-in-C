/*Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Selection sort
*/

#include<stdlib.h>
#include<stdio.h>

//function to create a list
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

//main function to perform selection sort 
void main()
{
	printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Selection sort\n\n\n");
	int limit,i,j,small,temp;
	
	printf("Enter the total number of elements in the list : ");
	scanf("%d",&limit);
	
	int *list = createList(limit);
	
	printf("\nBefore sorting : ");
	display(list,limit);
	
	//loop to sort the elements in the list using Selection sort method
	for(i=0;i<limit;i++)
	{
		small = i;      
		for(j=i+1;j<limit;j++)
		{
		    //find the index of small element
			if(list[j]<list[small])
			{
				small = j;
			}
		}
		//swap small and i
		temp = list[i];
		list[i] = list[small];
		list[small] = temp;
	}
		
	printf("\nAfter sorting : ");
	display(list,limit);        //call the display function 
}



