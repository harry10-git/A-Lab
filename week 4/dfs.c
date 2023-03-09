#include <stdio.h>
#define max 100

typedef struct {
	int arr[max];
	int top;
}stack;

void init(stack *s)
{
	s->top=-1;
}

void push(stack *s, int ele)
{
	++s->top;

	s->arr[s->top]= ele;

	//printf("%d ",ele);
}

int pop(stack * s)
{
	return s->arr[s->top--];
}




int main()
{

	int n;
	printf("Enter num of nodes : ");
	scanf("%d",&n);
	fflush(stdin);
	int arr[n][n];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j]=0;		
		}
	}



	int z=0;
	int k;

	fflush(stdin);
	while(z<n)
	{
		printf("Enter nodes connected to %c ",z);
		

		
		while(k!=-1 && k<n)
		{
			scanf("%d",&k);
			arr[z][k]=1;
		}
		k=0;
		z++;
	}



	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ",arr[i][j]);		
		}
		printf("\n");
	}

	printf("\n ----------------------- \n");



	//DSF operation

	int visited[n];
	for(int i=0; i<n; i++)
		visited[i]=0;

	stack s ;
	init(&s);

	int start =0;
	int count =1;
	push(&s,start);
	printf("%d ",start);
	visited[start]=1;

	int curr;
	int flag;
		
	while(count != n)
	{

		curr = s.arr[s.top];		
		flag=0;

		for(int i=0; i< n; i++)
		{

			if(arr[curr][i]==1 && visited[i] == 0)
			{
				push(&s,i);
				count+=1;
				visited[i]=1;
				printf("%d ",i);
				break;
			}

		}

		

	}



	
	return 0;
}