#include <stdio.h>
#define cols 6





int checkStop(int indegree[], int n)
{
    int count =0; 

    for(int m=0; m<n; m++)
    {
        if(indegree[m]<=0)
            count ++;
    }

    if(count ==n)
        return 0;
    return 1;
}

void setZeroes(int arr[][cols], int i, int n, int indegree[])
{
    indegree[i] = -1;

    for(int z=0; z<n; z++)
    {
        if(arr[i][z]==1)
        {
            indegree[z] -=1;
        }
    }
    
}

void topologicalSort(int arr[][cols], int indegree[], int n)
{
    for(int l=0; l<4; l++)
    {
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                printf("%d ", i);   
                setZeroes(arr,i, n, indegree);
            }
        }
    }




    printf("\n");
    for(int i=0; i<n ; i++)
    {
        printf("%d ",indegree[i]);
    }

}

int main()
{
    int arr[6][6] = {{0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0},
                     {0, 1, 0, 0, 0, 0},
                     {1, 1, 0, 0, 0, 0},
                     {1, 0, 1, 0, 0, 0}};

    int n = sizeof(arr[0]) / sizeof(int);

    int indegree[n];
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                indegree[j] += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", indegree[i]);
    }
    printf("\n");

    topologicalSort(arr, indegree, n);

    return 0;
}


void findIndegree(int arr[][cols], int indegree[], int n)
{
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                indegree[j] += 1;
        }
    }
}
