#include <stdio.h>


#define V 4

#define infinity 99999


void printSolution(int dist[][V]);


void floydWarshall(int dist[][V])
{
	int i, j, k;

	for (k = 0; k < V; k++) {

		for (i = 0; i < V; i++) {

			for (j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist);
}


void printSolution(int dist[][V])
{
	printf("\t Min dist matrix \n");
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == infinity)
				printf("%7s", "--");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}


int main()
{

	int graph[V][V] = { { 0, infinity, 3, infinity },
						{ 2, 0, infinity, infinity },
						{ infinity, 7, 0, 1 },
						{ 6, infinity, infinity, 0 } };


	floydWarshall(graph);
	return 0;
}
