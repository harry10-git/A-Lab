#include<stdio.h>
#include<stdlib.h>

void print();


void merge(int arr[],int l, int m, int r)
{
    int k;
    int n1= m -l +1;
    int n2 = r - m;
    
    int L[n1];
    int R[n2];

    // copy data to L and R
    for(int i=0; i<n1; i++)
        L[i]=arr[l+i];
    
    for(int i=0; i<n2; i++)
        R[i]= arr[m+1+i];

    k =l;

    int i=0;
    int j=0;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    // copying remaining elements

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=L[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;

        mergeSort(arr,l, m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}


int main()
{

    int arr[]={4,7,11,2,19,21,14};
    int n = sizeof(arr)/sizeof(int);
    

    mergeSort(arr,0,n-1);
    print(arr,n);

    return 0;
}


void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
}