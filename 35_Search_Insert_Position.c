#include <stdio.h>

int main(void){
	int nums[]={1,3,5,6};
	int target = 7;
	int len = (int) (sizeof(nums)/sizeof(nums[0]));
	int beg=0, end=len-1, mid=(beg+end)/2;
	int found = -1; 

	while(beg<=end){
		if(target < nums[mid]){
			end = mid-1;
			mid = (beg+end)/2;
		}
		else if(target > nums[mid]){
			beg = mid+1;
			mid = (beg+end)/2;
		}
		else if(target == nums[mid]){
			printf("index: %d", mid);
			found = 1;
			break;
		}
	}
	if(found == -1){
		// index at which the target can be inserted (not found case)
		printf("Not found: %d", mid+1);	
	}
}

/*

find the index or find the index where target can be placed 
in a sorted array in O(log n)

tests:

i/p: nums = [1,3,5,6]; taget = 5
o/p: 2

i/p: nums = [1,3,5,6]; taget = 2
o/p: 2

i/p: nums = [1,3,5,6]; taget = 7
o/p: 2


Need to perform binary seach O(log n)
*/