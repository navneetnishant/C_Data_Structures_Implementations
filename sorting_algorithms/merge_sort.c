#include <stdio.h>

void merge(int arr[], int p, int q, int r){
	int n1 = q - p + 1;
	// r - (q+1) +1 
	int n2 = r - q; 
	
	// arrays to store copy of arr[p..q] and arr[q+1..r]
	int L[n1], M[n2];

 	// make a copy of arr[p..q] in L[p..q]
	for(int i=0; i<n1; i++){
		L[i] = arr[p+i];
	}

	// make a copy of arr[q+1..r] in M[q+1..r]
	for(int i=0; i<n2; i++){
		M[i] = arr[q+1+i];
	}

	// i is current pointer for L[p..q] 
	// j is current pointer for M[q+1..r]
	// k is current pointer for the array arr[p..r] where we would place the sorted elements from L and M
	int i = 0;
	int j = 0;
	int k = p;

	// place smallest elements of L and M in arr[p..r] till one of them is exhausted.
	// while loop breaks if any one of L or M ends
	while(i<n1 && j<n2){
		if(L[i] <= M[j]){
			arr[k] = L[i];
			// once we place the smallest element of L and M, we move ahead the current pointer
			i++;
		}
		else{
			arr[k] = M[j];
			j++;
		}
		// we incrrement k to move to next location in arr[p..r] where we can insert next smallest of L and M
		k++;
	}

	// once any of L or M is exhausted, we simply copy the elements from the remaining array
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j<n2){
		arr[k] = M[j];
		j++;
		k++;
	}

	// we now have a sorted array arr[p..r] merged from two sorted arrays arr[p..q] and arr[q+1..r]
	// printf("merged\n");
}


void mergeSort(int arr[], int l, int r){
	//base case of recursion is l<r ie., when there is only one element left in the array (l=r) we stop
	if(l<r){
		// divide the array midway into two sub arrays 
		int m = (l+r)/2;
		// printf("l: \t %d \nm: \t %d \nm+1: \t %d \nr: \t %d\n\n", l, m, m+1, r);

		// call mergeSort on both the sub arrays to sort them
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		// call merge function to merge the two sorted sub arrays
		merge(arr, l, m, r);

	}
}


int main(void){
	int arr[] = {6, 5, 12, 10, 9, 1};
	int size = (int) (sizeof(arr)/sizeof(arr[0]));
	mergeSort(arr, 0, size-1);

	//print array after sorting
	for(int i=0; i<size; i++){
		printf("%d \t", arr[i]);
	}
	return 0;
}