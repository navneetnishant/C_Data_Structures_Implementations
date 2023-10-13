/*

Linear search = sequential search

=> We iterate over array comparing each element
with 'val' untill match is found

=> If all elements are iterated , match not found (pos = -1)

=> O(n); n=> number of elements in the array.

=> Best case: when 'val' is at the 0th index.
=> Worst case: when 'val' is at last index or 'val' not in list.

=> Used on unsorted lists

*/
#include <stdio.h>

int linearSearch(int * A, int val, int len){
	//pos => variable to store index of matched element
	int pos = -1;
	int i = 1;
	while(i<len){
		// val found
		if(A[i] == val){
			pos = i;
			break;
		}
		i++;
	}
	return pos;
}



int main(void){
	int A[] = {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};
	int val = 17;
	int len = (int) (sizeof(A)/sizeof(A[0]));
	//array is not sorted, hence linear search
	printf("%d\n", linearSearch(A, val, len));
	// printf("%d", (int) sizeof(A));
}
