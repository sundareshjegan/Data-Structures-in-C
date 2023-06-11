/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Radix Sort
*/
#include <stdio.h> 

// Define a function getMaximum
int getMaximum(int a[], int n) {  
    
    // Assign a[0] to a variable max
   int i,max = a[0];
    // Generate a loop from 1 to n
    for(i=0;i<n;i++)
    {
    // Check if a[i] > max. If so, assign a[i] to max
	   	if(a[i] > max)
	   	{
	   		max = a[i];
	   	}
   	}
    // return max
    return max;  
}  

// Count the digit
void countdigit(int a[], int n, int digit) 
{  
	int i;
    int output[n + 1];  
    int count[10] = {0};    
  
    // Generate loop from 0 to n and increment the count array by 1. Index of the count array is (a[i] / digit) % 10
    for(i=0;i<n;i++)
    {
    	count[(a[i]/digit)%10]++;
    }

    // Generate a loop from 1 to 10 and perform count[i] += count[i - 1];  
    for(i=1;i<=10;i++)
    {
    	count[i] += count[i-1];
    }	
    
    /* Generate a loop from n-1 to 0 and 
        output[count[(a[i] / digit) % 10] - 1] = a[i];  
        Decrement the count array by 1. Index of the count array is (a[i] / digit) % 10
    */
    for(i=n-1;i>=0;i--)
    {
    	output[count[(a[i]/digit)%10]-1] = a[i];
    	count[(a[i]/digit)%10]--;
    }
   
    // Generate a loop from 0 to n and assign output[i] to a[i]
 	for(i=0;i<n;i++)
 	{
 		a[i] = output[i];
 	}
}  
  
// Function to implement radix sort  
void radixsort(int a[], int n) {  
   
   int j;
  // get maximum element from array by invoking getMax(a, n)
  int max = getMaximum(a,n);
 
  
  for (j = 1; max / j > 0; j *= 10)  
    // Call the countdigit by passing a, n and j
    countdigit(a,n,j);
    
}  
  
// function to display 
void printArray(int a[], int n) {  
      // Generate a loop from 0 to n and display the elements 
    int i;
    printf("[ ");
    for(i=0;i<n-1;i++)
	{ 
		printf("%d, ",a[i]);
	}    printf("%d ]\n",a[i]);   
}  
  
void main() 
{
	printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Implementation of Radix Sort\n\n");
	int i,limit; 
	int a[50]; 
    // Get the necessary input from the user
    printf("Enter the total elements in the array : ");
    scanf("%d",&limit);
    
    for(i=0;i<limit;i++)
    {
    	printf("Enter the element %d : ",i+1);
    	scanf("%d",&a[i]);
    }
  
    // Display the elements before sorting by invoking printArray(a, n)
    printf("\nBefore Sorting : ");
    printArray(a,limit);
    
    // Call radixsort(a,n)
    radixsort(a,limit);

    // Display the elements after sorting by invoking printArray(a, n)
    printf("\nAfter Sorting : ");
    printArray(a,limit);
}  

