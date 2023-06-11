/*
Name : Sundareshwaran. J
Roll Number : 20UIT037
Program Name : Graph Representation - Adjacency Matrix
*/

#include <stdio.h>   

// function to initialize the matrix to zero 
int i,j;
void init(int a[][10], int v) {  
    // Generate an outer for loop from 0 to v
    // Generate an inner for loop from 0 to v
    // Assign 0 to a[i][j]
    
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            a[i][j]=0;
        }
    }
}  
  
// function to add edges to the graph
void insert(int a[10][10], int v, int i, int j) {  
  //Assign 1 to a[i][j] and a[j][i]
  a[i][j]=a[j][i]=1;
}  
  
// function to print the matrix elements 
void printMatrix(int a[10][10], int v) {  
    
    // Generate an outer for loop from 0 to v
        // print the value of i
        // Generate an inner for loop from 0 to v
            // print the value of a
        // print a new line
    for(i=0;i<v;i++)
    {
        printf("%d\t",i+1);
        for(j=0;j<v;j++)
        {
            printf("%d\t",a[i][j]);
        }printf("\n");
    }
}  
  
int main() 
{  
    printf("\nName : Sundareshwaran. J\nRoll Number : 20UIT037\nProgram Name : Graph Representation - Adjacency Matrix\n\n");

    int vertices, edges, s, e;
    int amatrix[10][10]; 
    // Get the number of vertices from the user
    printf("\nNumber of vertices from the user : ");
    scanf("%d",&vertices);
     
    // Call the init function by passing amatrix and vertices
    init(amatrix,vertices);
  
    // Get the number of edges from the user
    printf("\nNumber of edges from the user : ");
    scanf("%d",&edges);
    printf("\n");
    // Generate a loop from 0 to edges
    for(int i = 0; i < edges; i++)
    {
        //  Get the source and destination vertices
        printf("Enter the source vertex [0 to %d]: ", (vertices-1));
        scanf("%d",&s);
        
        printf("Enter the end vertex  [0 to %d]: ", (vertices-1));
        scanf("%d",&e);
        
        // Call the insert function by passing amatrix, vertices, s and e
        insert(amatrix,vertices,s,e);
        
    }
  
    // Display the matrix by calling printMatrix(amatrix, vertices)
    printf("\n\n\tAdjacency Matrix\n\t========= ======\n\n");
    printMatrix(amatrix, vertices);
      
    return 0;  
}  



