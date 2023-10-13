#include <stdio.h>
#include <string.h>


void push(int * stk, int val, int * tp){
	// printf("%c", stk[0]);
	if(*tp == -1){
		//stack empty
		stk[0]=val;
		*tp=*tp+1;
	}
	else{
		//stack has elements
		*tp = *tp + 1;
		stk[*tp]=val;
	}
	//returning top of stack
	// return *tp;
}


int main(void){
	int nums[]={0,0,1,1,1,2,2,3,3,4};
	int N = (int) (sizeof(nums)/sizeof(nums[0]));
	
	// k is number of unique elements in the array
	int ptr = -1, k=0; 
	
	int stack[N];
	int top = -1;

	// stack[0]='C';
	//pushing all characters of the string s to stack
	// for(int i=0; i<N; i++){
	// 	push(stack, nums[i], &top);	
	// }
	

	// printf("%c\t %d \n", stack[5], top);
	// finding unique elements and pushing in stack
	for(int i=0;i<N; i++){
		
		if(nums[i] == nums[ptr]){
			// printf("%d\n", stack[i]);
			continue;

		}
		else{
			nums[k] = nums[i];
			ptr=i;
			k++;
			//unique elements
			// printf("%d\n", nums[i]);
			push(stack, nums[i], &top);
		}
	}

	// printf("\t %d\n", stack[4]);

	// reading stack back into array
	// for(int i=0; i<k; i++){
	// 	nums[i]=stack[i];
	// }

	for(int i=0; i<k; i++){
		printf("%d\t", nums[i]);
	}

	return 0;
}
















/*

Array is sorted

input {1,1,2}

output {1,2,_} k=2

input {0,0,1,1,1,2,2,3,3,4}

output {0,1,2,3,4,_,_....} k=5

inplace removal of duplicates

Approach:

find unique elements of array and store in a stack

0 top 
0
1
1
1
2
2
3
3
4

for(int i=0; i<N; i++){
	while(stack[i] != stack[top]){
		printf("%d", )
	}
}

*/
