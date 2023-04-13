/* Write a program to compute the transitive closure of a given directed graph using
Warshall’s algorithm and analyse its time efficiency. Obtain the experimental results
for order of growth and plot the result. */

#include <stdio.h>
#include <stdlib.h>


void enterGraph();
void printMat();


void warshall(int ** mat, int n)
{

	// iterate till n

	for(int k=0 ; k<n; k++)
	{
		for(int i=0; i<n ; i++)
		{
			for(int j=0; j<n; j++)
			{
				mat[i][j] = mat[i][j] || mat[i][k] && mat[k][j];
			}
		}

	}


}


int main()
{

	int n;
	int ** mat;
	printf("Enter num of nodes : ");
	scanf("%d",&n);

	mat = (int **)malloc(n * sizeof(int*));

	for(int i=0; i<n; i++)
	{
		mat[i] = calloc(n , sizeof(int));
	}


	enterGraph(mat,n);
	// printing mat
	printMat(mat,n);

	// Warshall algo
	warshall(mat,n);
	printf("\n--------- after warshall ----------------\n");
	printMat(mat,n);

	return 0;
}



void enterGraph(int **mat, int n)
{
	int x;
	for(int i=0; i<n; i++)
	{
		printf("Enter nodes connected to %d ",i);
		scanf("%d",&x);
		while(x!=-1)
		{	
			
			mat[i][x] =1;
			scanf("%d",&x);
		}	
	}
}

void printMat(int **mat, int n)
{
	printf("\nPrinting the matrix \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}

}
