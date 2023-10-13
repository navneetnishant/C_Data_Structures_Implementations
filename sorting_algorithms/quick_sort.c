// Quick Sort

#include <stdio.h>

int partition(int arr[], int low, int high){
	//selecting last element as pivot
	int pivot = arr[high];
	//selecting greatest element as first element
	int i = low;
	for(int j = low; j<high; j++){
		if(arr[j] <= pivot){
			//swap greatest element with the element smaller than pivot
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			//increment i to point to next greatest element in array
			i++;
		}
	}
	// we now swap pivot with the element pointed by i
	int temp = arr[high];
	arr[high]=arr[i];
	arr[i] = temp;
	
	//return the pivot's current position

	return i;

}

void quickSort(int arr[], int low, int high){
	int pivot = partition(arr, low, high);
	printf("%d %d %d\n", low, pivot, high);
	// if(low < high){
	// 	int pivot = partition(arr, low, high);
	// 	printf("%d %d %d\n", low, pivot, high);
	// 	quickSort(arr, low, pivot);
	// 	quickSort(arr, pivot+1, high);
	// }
}

int main(void){
	int arr[]={8, 7, 2, 1, 0, 9, 6};
	int size = (int) (sizeof(arr)/sizeof(arr[0]));
	// printf("%d", size);
	quickSort(arr, 0, size-1);
	return 0;
}


/*
8, 7, 2, 1, 0, 9, 6
				 pivot
2, 7, 8, 1, 0, 9, 6

2, 1, 8, 7, 0, 9, 6

2, 1, 0, 7, 8, 9, 6

2, 1, 0, 6, 8, 9, 7
*/