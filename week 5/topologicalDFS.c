#include <stdio.h>
#include <stdlib.h>

#define cols 6
#define max 10

typedef struct
{
    int arr[max];
    int top;
} stack;

void init(stack *s)
{
    s->top = -1;
}

void push(stack *s, int ele)
{
    s->top++;
    printf("\n pushing %d ", ele);
    s->arr[s->top] = ele;
}

int pop(stack *s)
{
    //printf(" rem %d ",s->arr[s->top]);
    return s->arr[s->top --];
}

int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int atTop(stack *s)
{
    return s->arr[s->top];
}

int check(int visited[], int n)
{
    int sum =0;

    for(int i=0; i<n; i++)
    {
        sum = sum+ visited[i];
    }

    if(sum != n-1)
        return 1;
    return 0;
}

void topologicalSort(int graph[][cols], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int res[6];
    int start = 0;
    int curr;

    stack *s = (stack *)malloc(sizeof(stack));
    init(s);

    push(s, start);
    visited[start] = 1;
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            push(s,i);
            break;
        }
    }
    



    //while (!isEmpty(s))
    // for(int z=start; z<n; z++)
    // {
        
    //         for (int i = 0; i < cols; i++)
    //         {
    //             if (visited[i] == 0 && graph[curr][i] == 1)
    //             {
    //                 visited[i] = 1;
    //                 printf("--------------");
    //                 push(s, i);
    //                 count++;
    //                 break;
    //             }
    //         }
    //         curr = pop(s);
        
    // }


}

int main()
{
    int graph[6][6] = {{0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 1, 0, 0},
                       {0, 1, 0, 0, 0, 0},
                       {1, 1, 0, 0, 0, 0},
                       {1, 0, 1, 0, 0, 0}};

    int n = sizeof(graph[0]) / sizeof(int);

    

    topologicalSort(graph, n);

    return 0;
}