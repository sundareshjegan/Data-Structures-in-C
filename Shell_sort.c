/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Implementation of Shell Sort
*/

	#include <stdio.h>
void shellsort(int a[],int n)
{
    int i,j,k,temp;
    // Generate an outer loop from n/2 to 0, decrement the loop as i/=2
    for (i=n/2;i>0;i=i/2)
    {
    	// Generate an inner loop j from i to n
        for (j=i;j<n;j++)
        {
        	// Generate an innermost loop k from j to i, decrement the k value by i and include the condition a[k - interval] > temp
            for(k=j-i;k>=0;k=k-i)
            {
                if (a[k+i] >= a[k])
				{
                    break;
				}
                else
                {
                // Assign a[k-i] to a[k]
        		// Assign temp to a[k] 
                	temp = a[k];
                   	a[k] = a[k+i];
                   	a[k+i] = temp;
            	}
            }
        }
    }
}

// Define a function to display
void display(int a[],int b)
{
	// Generate a loop from 0 to n and display the elements
	int i;
	printf("[ ");
	for(i=0;i<b-1;i++)
	{ 
		printf("%d, ",a[i]);
	}    printf("%d ]\n",a[i]);  
}

//main function
int main()
{
	printf("\nName : Sundareshwaran .J\nRoll Number : 20UIT037\nProgram Name : Implementation of Shell Sort\n\n");
	// Declare the neccessary variables
    int a[30];
    int i,num;
    
    // Get the maximum limit from the user
    printf("Enter total no. of elements : ");
    scanf("%d", &num);
    
    // Generate a loop from 0 to limit and get the input elements
    for(i=0;i<num;i++)
    {
    	printf("Enter the element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    
    // Display the elements before sorting by invoking the display(a, limit) function
 	printf("\nBefore shell Sorting :");
	display(a,num);
	
	// Call the shellsort by passing a, limit
    shellsort(a,num);
    
    // Display the elements after sorting by invoking the display(a, limit) function
    printf("\nAfter shell sorting :");
	display(a,num);
    return 0;
}
