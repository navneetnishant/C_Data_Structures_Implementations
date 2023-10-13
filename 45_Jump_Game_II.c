#include <stdio.h>

int main(void){
	int nums[]={2,3,1,1,4};
	int n = (int) (sizeof(nums)/sizeof(nums[0]));
	int jumps=0;
	for(int i=0; i<n; i++){
		if(i == n-1){
			break;
		}
		if(i+nums[i]+1 <= n-1){
			i=i+nums[i]+1;
			jumps=jumps+1;	
		}
		else if(i+nums[i]+1 > n-1){
			printf("Entered\n");
			jumps=jumps+1;
			break;    
		}
		printf("i: %d\t jumps: %d\n", i, jumps);
	}
	printf("%d\n", jumps);
}


/*
i=0, jump=1
i=3, jump=2
i=5, 
*/