/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Heap
*/

#include <stdio.h>

int size = 0,i,j;

void swap(int *a, int *b) {
	// Swap the values *a and *b using *temp
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Heapify the tree
void heapify(int array[], int size, int i) {
	// Check if the size is 1. If yes, display "There is only one element in Heap"
	if(size == 1)
	{
		printf("There is only one element in the Heap");
	}
	else
	{
		int largest = i;
	    int left = 2 * i + 1;
    	int right = 2 * i + 2;
    	
    	if(left<size && array[left]>array[largest])
    	{
    		largest = left;
    	}
    	else if(right>size && array[right] > array[largest])
    	{
    		largest = right;
    	}
    	else if(largest!=1)
    	{
    		swap(&array[i],&array[largest]);
    		heapify(array,size,largest);
    	}
    }
		
	/* Else, Find the largest among the root, left child and right child
	    To do so, declare these three variables:
	    int largest = i;
	    int left = 2 * i + 1;
    	    int right = 2 * i + 2;

	    Check whether the left is less than size and array[left] is greater than array[largest]. 
	    If yes, assign left to largest.

	    Check whether the right is greater than size and array[right] is greater than array[largest]. 
	    If yes, assign right to largest.

 	    Check whether largest not equals i. 
	    If yes, call swap function by passing &array[i] and &array[largest] 
	    as well as call heapify function by passing array, size and largest.
	*/

   
}

// Insert function
void insert(int array[], int temp) {
	// Check whether the size value is 0. If yes, assign temp to array[0] and increment the size by 1
	if(size == 0)
	{
		array[0] = temp;
		size +=1;
	}
	else
	{
		array[size] = temp;
		size +=1;
		for(i=(size/2)-1;i>=0;i--)
		{
			heapify(array,size,i);
		}
	}
	/* Else, assign temp to array[size], increment the size by 1 and 
	    generate a loop i from size/2-1 to 0 (decrementing loop); 
	       call the heapify function by passing array, size, i
	*/

}

// Delete function
void deleteRoot(int array[], int num) {
	/* Generate a loop i from 0 to size (incrementing loop);
		Check whether num equals array[i]. If yes, break.
	*/
	for(i=0;i<size;i++)
	{
		if(num == array[i])
		{
			break;
		}
	}
	
	// Call swap function by passing &array[i] and &array[size-1]
	swap(&array[i],&array[size-1]);
	
	// Decrement the value of size
	size-=1;
	
	/* Generate a loop i from size/2-1 to 0 (decrementing loop); 
	       call the heapify function by passing array, size, i
	*/
	for(i=(size/2)-1;i>=0;i--)
	{
		heapify(array,size,i);
	}


}

// Display function
void display(int array[], int size) {
	// Generate a loop i from 0 to size and display the array values
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
}

// Main function
 void main() 
{
    printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Heap\n\n");
	// Declare an array
	int array[50],limit,element,j;
	
	// Get the maximum number of element from the user
	printf("Enter the total elements : ");
	scanf("%d",&limit);
	
	// Generate a loop to get the input element and call the insert function by passing the array and element
	for(j=0;j<limit;j++)
	{
		printf("Enter the element %d : ",j+1);
		scanf("%d",&array[j]);
		insert(array,array[j]);
	}
	
	// Call the display function by passing the array and size
	display(array,size);
	
	// Get the element to be deleted and call the delete function by passing array and element
	printf("\nEnter the element to be deleted : ");
	scanf("%d",&element);
	deleteRoot(array,element);
	
	// Call the display function by passing the array and size
	display(array,size);
}


