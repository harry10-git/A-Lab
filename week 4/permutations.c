#include <stdio.h>

int res[24][4];
int curr=0;

int job[4][4]= {{2,1,4,3},
                {3,2,1,4},
                {4,3,1,2},
                {3,1,7,8}};




void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end)
{
    

    if(start==end)
    {
        //printarray(arr, end+1);
        //return;
        for(int i=0; i<4; i++)
        {
            res[curr][i]=arr[i];
            
        }
        curr+=1;

    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit and calling permutation on the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}



int main()
{
    //taking input to the array
    int size=4;
    
    int i;
    int arr[]={0,1,2,3};
    //int arr[size];
    //for(i=0;i<size;i++)
      //  scanf("%d",&arr[i]);
    //calling permutation function
    //int arr[]= {1,2,3,4};

    permutation(arr, 0, size-1);

    for(int i=0; i<24; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }

    printf("//Calcs here \n");

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    int vals[24];
    

    for(int i=0; i<24; i++)
    {
        vals[i]=0;

        for(int j=0; j<4; j++)
        {
            vals[i] += job[j][res[i][j]]; 
        }
    }

    int min= vals[0];
    int curr=0;

    for(int i=0; i<24; i++)
    {
        printf("%d\n",vals[i]);
        if(vals[i] < min)
        {
            curr = i;
            min=vals[i];
        }
    }

    printf("///////// The answer is ///////////");

    for(int i=0; i<4; i++)
    {
        printf("%d ",res[curr][i]);
    }


    
   


    return 0;
}