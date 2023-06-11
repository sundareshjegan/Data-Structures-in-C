/* Name : Sundareshwaran J
Roll Number : 20UIT037
Program Name : Implementation of List ADT
*/
#include<stdio.h>
int index=0,list[50],size;

void create()
{
	printf("Enter the size of List:\n");
	scanf("%d",&size);
	if(size<=0)
	{
		printf("Invalid Input\n");
		create();
	}
}
void insertFirst(int data)
{	
    int i;
	if(size==index)
	{
		printf("Sorry List is Full\n");	
	}
	else
	{
		for(i=(index-1);i>=0;i--)
		{	
			list[i+1]=list[i];
		}
		list[0]=data;
		index++;
		printf("Successfully Inserted\n");
	}
}
void insertLast(int data)
{
	if(index==size)
	{
		printf("Sorry List is Full\n");
	}
	else
	{
		list[index++]=data;
		printf("Successfully Inserted\n");		
	}
}

void insertAfter(int data ,int value)
{
	int i=0,temp=-1;
	if(index==size)
	{
		printf("Sorry List is Full\n");
	}
	else
	{
		for(i=0;i<index;i++)
		{
			if(list[i]==value)
			{
				temp=i;
				break;
			}
		}
		if(temp!=-1)
		{
			for(i=(index-1);i>temp;i--)
			{
			    list[i+1]=list[i];
			}
			list[temp+1]=data;
			index++;
			printf("Successfully Inserted\n");
		}else
		{
			printf("Element not Found");
		}
	}
}
void insertBefore(int data ,int value)
{
	int i=0,temp=-1;
	if(index==size)
	{
		printf("Sorry List is Full\n");
	}
	else
	{
		for(i=0;i<index;i++)
		{
			if(list[i]==value)
			{
				temp=i;
				break;
			}
		}
		if(temp!=-1)
		{
			for(i=(index-1);i>=temp;i--)
			{
				if(list[i]==value)
				{
					list[i+1]=list[i];
					list[i]=data;
				}
				else
				{
				    list[i+1]=list[i];
				}
			}
			index++;
			printf("Successfully Inserted\n");
		}
		else
		{
			printf("Element not Found");
		}
	}
}

void insertAtLocation(int data,int location)
{
    int i=0,temp=-1;
	if(index==size)
	{
		printf("Sorry List is Full\n");
	}
	else
	{
		if(location>0 & location<=index)
		{
			temp=0;
		}
		if(temp!=-1)
		{
			for(i=(index-1);i>=location-1;i--)
			{
				if(i==location-1)
				{
					list[i+1]=list[i];
					list[i]=data;
				}
				else
				{
				    list[i+1]=list[i];
				}
			}
			index++;
			printf("Successfully Inserted\n");
		}
		else
		{
			printf("Invalid location");
		}
	}
}

void DeleteFirst()
{
    int i;
	if(index==0)
	{
		printf("Sorry List empty\n");	
	}
	else
	{
		for(i=0;i<index;i++)
		{	
			list[i]=list[i+1];
		}
		index--;
	}
}

void DeleteLast()
{
	int i;
	if(index==0)
	{
		printf("Sorry List empty\n");	
	}
	else
	{
		index--;
	}
}
void DeleteAfter(int value)
{
    int i=0,temp=-1;
	if(index==0)
	{
		printf("Sorry List is empty\n");
	}
	else
	{
		for(i=0;i<index;i++)
		{
			if(list[i]==value)
			{
				temp=i;
				break;
			}
		}
		if(temp!=-1)
		{
			for(i=temp+1;i<index;i++)
			{
			    list[i]=list[i+1];
			}
			
			index--;
		}
		else
		{
			printf("Element not Found");
		}
	}
}

void DeleteBefore(int value)
{
    int i=0,temp=-1;
	if(index==0)
	{
		printf("Sorry List is empty\n");
	}
	else
	{
		for(i=0;i<index;i++)
		{
			if(list[i]==value)
			{
				temp=i;
				break;
			}
		}
		if(temp!=-1)
		{
			for(i=temp-1;i<index;i++)
			{
			    list[i]=list[i+1];
			}
			index--;
		}
		else
		{
			printf("Element not Found");
		}
	}
}

void DeleteAtLocation(int location)
{
    int i=0,temp=-1;
	if(index==0)
	{
		printf("Sorry List is empty\n");
	}
	else
	{
		if(location>0 & location<=index)
		{
			temp=0;
		}
		if(temp!=-1)
		{
			for(i=location-1;i<index;i++)
			{
				list[i]=list[i+1];
			}
			index--;
		}
		else
		{
			printf("Invalid location");
		}
	}
}

void search(int value)
{
	int i=0,temp=-1;
	for(i=0;i<index;i++)
	{
		if(list[i]==value)
		{
			temp=i;
			break;
		}
	}
	if(temp!=-1)
	{
		printf("Element Found");
	}
	else
	{
		printf("Element not Found");
	}
}
void display()
{
	int i;
	if(index==0)
	{
		printf("List is Empty");
		printf("[ ]");
	}
	else
	{
	    printf("The Elements are:\n");
    	printf("[");
    	for(i=0;i<(index-1);i++)
    	{
    		printf("%d ,",list[i]);
    	}
    	printf("%d]",list[i]);
	}
}

void main()
{
	int choice,data,value;
	create();

	do
	{
    	printf("\n     Menu\n     ----\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Insert Before\n5.Insert at a Location\n");
    	printf("6.Delete First\n7.Delete Last\n8.Delete After\n9.Delete Before\n10.Delete at a Location\n11.search\n12.Display\n13.Exit\n");
    	printf("\nEnter the choice: ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
    			printf("INSERT FIRST\n");
    			printf("Enter the Element : ");
    			scanf("%d",&data);			
    			insertFirst(data);
    			break;
    			
    		case 2:
    			printf("INSERT LAST\n");
    			printf("Enter the Element : ");
    			scanf("%d",&data);			
    			insertLast(data);
    			break;
    			
    		case 3:
    			printf("INSERT AFTER\n");
    			printf("Enter the element to be inserted : ");
    			scanf("%d",&data);
    			printf("Insert After ?: ");
    			scanf("%d",&value);
    			insertAfter(data ,value);
    			break;
    			
    		case 4:
    			printf("INSERT BEFORE\n");
    			printf("Enter the element to be inserted : ");
    			scanf("%d",&data);
    			printf("Insert Before ?: ");
    			scanf("%d",&value);
    			insertBefore(data ,value);
    			break;
    			
    		case 5:
    			printf("INSERT AT A LOCATION\n");
    			printf("Enter the element to be inserted : ");
    			scanf("%d",&data);
    			printf("Insert Location ?: ");
    			scanf("%d",&value);
    			insertAtLocation(data ,value);
    			break;
    			
    		case 6:
    			printf("DELETE FIRST\n");
    			DeleteFirst();
    			break;
    			
    		case 7:
    			printf("DELETE LAST\n");
    			DeleteLast();
    			break;
    			
    		case 8:
    			printf("DELETE AFTER\n");
    			printf("Delete the element after? : ");
    			scanf("%d",&value);
    			
    			DeleteAfter(value);
    			break;
    			
    		case 9:
    			printf("DELETE BEFORE\n");
    			printf("Delete the element before? : ");
    			scanf("%d",&value);
    			
    			DeleteBefore(value);
    			break;
    			
    		case 10:
    			printf("DELETE AT A LOCATION\n");
    			printf("Delete the element at location? : ");
    			scanf("%d",&value);
    			
    			DeleteAtLocation(value);
    			break;
    			
    		case 11:
    			printf("SEARCH\n");
    			printf("Enter the element to be searched : ");
    			scanf("%d",&value);
    			
    			search(value);
    			break;
    			
    		case 12:
    			display();
    			break;
    			
    		case 13:
    			printf("Bye\n");
    			break;
    			
    		default:
    			printf("Invalid Input\n");
    	}
	}while(choice!=13);
}



