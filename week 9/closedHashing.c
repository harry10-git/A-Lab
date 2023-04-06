/* Write a program to construct the closed hash table. Find the number of key
comparisons in successful search and unsuccessful search. */

#include <stdio.h>
#include<stdlib.h>
#define SIZE 11



void addHash(int arr[], int num)
{
	int rem = num%SIZE;
	int opcount = 0;

	if(arr[rem] ==-1)
	{
		arr[rem] = num;
		printf("opcount to insert %d:\t %d \n",num,opcount);
		printf("%d inserted at %d\n",num,rem);
		return;
	}

	int ptr = rem;

	while(arr[ptr]!=-1)
	{
		if(ptr==SIZE-1)
			ptr = -1;

		ptr +=1;	
		opcount ++;
	}

	arr[ptr] = num;
	printf("%d inserted at %d\n",num,ptr);

	printf("opcount to insert %d:\t %d \n",num,opcount);



}


int main()
{

	int nums[] ={30,20,56,75,31,19};

	int n = sizeof(nums)/sizeof(nums[0]);

	int arr[SIZE];
	for(int i=0; i<SIZE; i++)
	{
		arr[i]= -1;
	}

	
	for(int i=0; i<n ; i++)
	{
		addHash(arr,nums[i]);   // adding each element for the nums array to the hash array
	}	


	printf("------------------------ HASH TABLE ------------------------\n");
	for(int i=0; i<SIZE; i++)
	{	
		if(arr[i]!=-1)
		printf("%d ", arr[i]);
	}
	printf("\n");









	return 0;
}
