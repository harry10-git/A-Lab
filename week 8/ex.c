#include <stdio.h>


void heapify(int h[], int n)
{
	int i, k, v, heapify,j;

	for(i = (n/2); i>=1 ; i--)
	{
		k=i; v= h[k]; heapify =0;

		while(heapify ==0 && 2*k<=n)
		{
			j = 2*k;
			if(j<n)
				if(h[j] < h[j+1])
					j = j+1;

			if(v >=h[j])
				heapify = 1;
			else{
				h[k] = h[j];
				k = j;
			}
		}
		h[k] = v;
	}
} 



int main()
{
	int h[20], i ,n;
	int arr[] ={2,9,7,6,5,8};
	n = sizeof(arr)/ sizeof(int);

	heapify(arr,n);

	printf("After heapify \n");
	for(int i =0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}