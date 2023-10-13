#include <stdio.h>

int main(void){
	int nums[]={0,1,2,2,3,0,4,2};
	//value to match
	int val=2; 
	int len = (int) (sizeof(nums)/sizeof(nums[0]));
	int last=-1, ptr=0, k;
/*
	last=stores position to place the unmatched element
	ptr=stores position of unmatched element to swap
	k=counts the number of unmatched elements in the array 	
*/

	for(int i=0; i<len; i++){
		if(nums[i] != val){
			//check if first element of array or no match yet
			if(ptr == 0 || last == -1){
				ptr++;
				// increment unmatch count 
				k++; 
				continue;
			}
			//when not first element and already found a match(last!=-1)
			else{
				//store position of unmatched in ptr
				ptr=i; 
				k++;
				//swap values at last and ptr 
				int temp = nums[last];
				nums[last] = nums[ptr];
				nums[ptr] = temp;

				//increment last to point to next element to overwrite
				last++; 
			}
		}
		// nums[i] matches val 
		else{
			//check first match
			if(last == -1){
				last = i;
			}
		}
	}
	//number of unmatched elements
	printf("%d\n", k);
	//nums array after modification
	for(int i=0; i<len; i++){
		printf("%d\t", nums[i]);
	}
}






/*
ptr=4
last=3
0,1,2,2,3,0,4,2

	    lnptr
nums = [2,3,2,2,3] ; val = 2

o/p: k=2, nums[2,2,_,_]

sort arra in ascending

if nums[i] != val > ptr=i; k++ ; nums[ln]=num[ptr];
else ln = i;
ln  ptr         
2,  3,  2,  2,  3
------

when non matching value found, swap value at ln and ptr (only if ln!=0 && ptr!=0 && match>1) 
and ln++ ptr++
k++ 

when first time find a matching,  we position ln there else we ptr++ else match++;

		    ln
				   ptr
3,  3,  3,  2,  2,  2

i=0, ln=0, ptr=0
i=1, ln=0, ptr=1, k=1, 
i=2, ln=2, ptr=1, k=1
i=3, 

					ln
							ptr
0,	1,	3,	0,	4,	2,	2,	2          val=2


k=4



*/