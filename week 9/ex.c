/*
	Write a program to sort set of integers using comparison counting algorithm.
*/

#include<stdio.h>
#include<stdlib.h>

void comparisonCountingSort(int arr[], int res[], int n)
{
	int count[n];
	for(int i=0; i<n; i++)
	{
		count[i]=0;
	}


	for(int i=0; i<n-1 ; i++)
	{
		for(int j= i+1; j<n; j++)
		{
			if(arr[i]<arr[j])
				count[j] +=1;
			else
				count[i] +=1;
		}
	}

	// filling the values in res
	for(int i=0; i<n; i++)
	{
		res[count[i]]= arr[i];
	}

}



int main()
{

	int n;
	printf("Enter num of elements in the array ");
	scanf("%d",&n);

	int arr[n];

	// printf("Enter elements\n");

	for(int i=0; i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}

	int res[n]; // to store the sorted array
	for(int i=0; i<n; i++)
	{
		res[i]=0;
	}


	comparisonCountingSort(arr,res,n);

	for(int i=0; i<n ; i++)
	{
		printf("%d ",res[i]);
	}



	return 0;
}