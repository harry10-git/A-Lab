#include <stdio.h>
#include <stdlib.h>

// Global variable
int opcount;

// Function Prototypes
void heapify(int*, int, int);
void heapsort(int*, int);
void swap(int*, int, int);


// Main Driver Function
int main() {
	int *arr, n;

	// Input number of elements
	printf("Enter the number of elements in array: ");
	scanf("%d", &n);

	// Memory Allocation
	arr = (int*) calloc(n+1, sizeof(int));

	// Input elements
	printf("Enter %d elements into array: ", n);
	for(int i=1; i<=n; i++) {
		scanf("%d", arr+i);
	}

	// Print Initial Array
	printf("\nArray before sorting:\n");
	for(int i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// Call to sort
	heapsort(arr, n);

	// Print Final Array
	printf("\nArray after sorting:\n");
	for(int i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// Free memory allocated
	free(arr);

	return 0;
}

// Function to sort array using heapsort
void heapsort(int* arr, int n) {
	// Initialize operation count to 0
	opcount = 0;
	
	// Heapify the total array
	heapify(arr, n, 1);

	// Iterate through the array
	for(int i=n; i>1; i--) {
		// Swap the largest element at root to the end of the array
		swap(arr, 1, i);

		// Heapify only the root of the array
		heapify(arr, i-1, 0);
	}

	// Print operation count
	printf("\nOperation Count: %d\n", opcount);
}

// Heapify Function
void heapify(int* h, int n, int all) {
	// Parameters:
	//		h - input array
	// 		n - size of the array
	// 		all - 
	// 				if 1 heapify the whole array
	// 				else heapify only the root, i.e. element at index 1

	int i, k, v, heapify, j;

	for(i = all ? (n/2) : 1; i >= 1; i--) {
		k = i;
		v = h[k];
		heapify = 0;
		while(heapify==0 && 2*k<=n) {
			j = 2*k;

			opcount++;
			if(j < n) 
				if(h[j] < h[j+1])
					j=j+1;

			opcount++;
			if(v >= h[j])
				heapify=1;
			else {
				h[k] = h[j];
				k = j;
			}
		}
		h[k]=v;
	}
}

// Function to swap elements at position i and j
void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}