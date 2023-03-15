#include<stdio.h>

void insertionSort(int arr[], int n)
{

    int j;
    for(int i=1; i<n; i++)
    {
        j = i-1;
        int curr = arr[i];

        while(arr[j] > arr[i] && j>=0)
        {
            arr[j+1]= arr[j]; 
            j--;
        }
        arr[j+1]= curr;;

    }

}



int main()
{

    int arr[] ={3,15,8,7,12};
    int n = sizeof(arr)/sizeof(n);

    insertionSort(arr , n);

    for(int i=0; i<n ; i++)
    {
        printf("%d  ",arr[i]);
    }



    return 0;
}