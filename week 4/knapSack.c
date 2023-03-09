// Knapsack problem 

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int sum =0;
	int limit = 7;
	int col=2;

	int arr[16][7];

	for(int i=0; i<16; i++)
	{
		for(int j=0; j<7; j++)
		{
			arr[i][j]=0;

		}
	}

	int w[]= {1,2,3,4};
	int v[]= {2,5,3,6};

	int total=0;

	for(int i=0; i<16; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(i & (1<<j))
			{
				sum = sum+ w[j];
				// filling arrays with values
				arr[i][col]=w[j];
				total = total + v[j]; 
				col+=1;
			}
		}
			arr[i][0]= sum;
			arr[i][1]=total;
			col=2;
			total =0;
		
		sum =0;
	}


	for(int i=0; i<16; i++)
	{
		for(int j=0; arr[i][j]!='\0'; j++)
		{
			printf("%d ",arr[i][j]);
			
		}
		printf("\n");
	}

	printf("Finding the max \n");
	int max = 0;
	int currMax =arr[0][1];

	for(int i=1; i<16; i++)
	{
		if(arr[i][0]<= limit && arr[i][1]>currMax)
		{
			max=i;
			currMax= arr[i][1];
		}	
	}

	// Displaying Max seq

	for(int i=2; arr[max][i]!=0; i++)
	{
		printf("%d ",arr[max][i]);
	}

	printf("\n");



	return 0;
}