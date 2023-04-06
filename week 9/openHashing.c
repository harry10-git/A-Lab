/*Write a program to construct the Open hash table. Find the number of key
comparisons in successful search and unsuccessful search. This should be done by
varying the load factor of the hash table. You may consider varying the number of
keys for a fixed value of hash table size say m=10 and n=50, 100, and 200. This
should be repeated for at least four different hash table sizes say m= 20, m=50. */

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 

#define SIZE 10


typedef struct node{
	int data;
	struct node * next;
}node;

node * createNode(int val)
{
	node * temp = malloc(sizeof(node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}


void addHash(node * arr[], int num)
{

	int rem = num%SIZE;

	node * ptr = arr[rem];

	if(ptr ==NULL)
	{
		arr[rem] = createNode(num);
		return;
	}

	while(ptr->next !=NULL)
	{
		ptr= ptr->next;
	}
	ptr->next = createNode(num);

}


void display(node * arr[])
{
	printf("Find elements with remainder: ");
	int n;
	scanf("%d",&n);

	node * ptr = arr[n];

	while(ptr != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr ->next;
	}
	printf("\n");
}

void findEle(node * arr[])
{
	int ele ;
	int opcount =0;
	printf("Enter element to find: ");
	scanf("%d",&ele);

	bool found = false;

	int rem = ele % SIZE;

	node * ptr = arr[rem];

	while(ptr!=NULL)
	{
		if(ptr->data == ele)  // if element is found
		{
			found = true;
			opcount++;
			break;
		}
		ptr= ptr->next;
		opcount ++;
	}


	if(found)
		printf("%d was Found ---------- OPCOUNT %d\n",ele,opcount);
	else 
		printf("NOT FOUND ----------- OPCOUNT= %d\n",opcount);
}


int main()
{



	node * arr[SIZE];
	for(int i=0; i<SIZE; i++)
	{
		arr[i]= NULL;
	}


	// INSERTION of elements

	for(int i=0; i<50; i++)
	{
		addHash(arr,i);
	}

	display(arr);


	findEle(arr);

	return 0;
}



