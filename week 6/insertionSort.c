#include<stdio.h>

void insertionSort(int arr[], int n)
{


    for(int i=1; i<n; i++)
    {
        int key = arr[i];

        int j= i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]= arr[j];
            j = j-1;
        }
        arr[j+1]=key;

    }

}


int main()
{
    int arr[]={11,24,9,8,5};
    int n= sizeof(arr)/sizeof(int);


    insertionSort(arr,n);


    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}