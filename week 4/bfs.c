#include <stdio.h>
#include <stdbool.h>
#define max 100

typedef struct{
	int arr[max];
	int front;
	int rear;
}queue;

void init(queue *q)
{
	q->front =-1;
	q->rear =-1;
}

void enq(queue * q, int ele)
{
	printf("enq %d ",ele);
	q->arr[++q->rear]=ele;
}

int deq(queue * q)
{
	if(q->front > q->rear || q->rear ==-1)
	{
		return -1;
	}
	return q->arr[q->front++];
}

bool isEmpty(queue *q)
{
	if(q->front > q->rear)
		return true;

	return false;
}



int main()
{
	int arr[5][5];
	int n=5;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j]=0;		
		}
	}

	// adding verices
	arr[0][1]=1;
	arr[0][4]=1;
	arr[1][2]=1;
	arr[2][3]=1;
	arr[2][4]=1;
	arr[3][2]=1;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ",arr[i][j]);		
		}
		printf("\n");
	}


	// BFS Operations 
	int visited[n];
	for(int i=0; i<n; i++)
		visited[i]=0;

	visited[0]=1;

	queue q;
	init(&q);

	int start=0;
	enq(&q,start);
	int count=1;

	int curr;
	while(q.front < q.rear)
	{
		curr= deq(&q);
		//printf("%d ",curr);
		for(int i=0; i<n; i++)
		{
			if(arr[curr][i]==1 && visited[i]==0)
			{
				enq(&q,i);
				visited[i]=1; 	
				count +=1;
			}

		}


	}




	return 0;
}





