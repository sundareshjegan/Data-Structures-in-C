#include<stdio.h>
void create(int a[], int n)
{
    // Get the input elements from the user for the limit of n
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void display(int a[], int n)
{
    // Display the elements
    int i;
    printf("[ ");
    for (i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("]");
}
void merge(int a[], int b[], int n1, int n2)
{
    // Assign the value of n1 to a variable j
    int i=0,j;  
     
    // Generate the loop for n2 and store the values of b to a
    for(j=n1;i<=n2;j++)
    {
        a[j] = b[i++];
    }
    // Start the index of a from j and increment it
}

int main()
{
    // Declare the neccessary variables
    int a[100],b[50],n1,n2;
    int j;
    
    // Get the limit for the list 1
    printf("Enter the limit for List-1 :\n");
    scanf("%d",&n1);
    if(n1<0)
        printf("Sorry... Invalid input");
    else
    {
        //Call the create function by passing the necessary parameters
        printf("Enter the elements for list-1 : \n");
        create(a,n1);  
    
        // Call the display function to display the list
        printf("List - 1 = ");
        display(a,n1);    
    
        // Get the limit for the list 2
        printf("\nEnter the limit for List 2 : \n");
        scanf("%d",&n2);
        if(n2<0)
            printf("Sorry... Invalid Input");
        else
        {
            // Call the create function by passing the necessary parameters
            printf("Enter the elements for list-2 : \n");
            create(b,n2);  
    
            // Call the display function to display the list
            printf("List - 2 = ");
            display(b,n2);  
    
            // Call the merge function by passing the necessary parameters
            merge(a,b,n1,n2);
    
            // Call the display function to display the merged list
            printf("\n\nThe Merged List is : \n");
            display(a,n1+n2);
        }
    }
    return 0;
}

