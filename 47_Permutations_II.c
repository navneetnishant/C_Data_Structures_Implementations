#include <stdio.h>
#include <math.h>

int * genPerms(int * nums){
	return genPerms(nums)
}

int main(void){
	int nums[] = {1,2,3};
	int len = (int) (sizeof(nums)/sizeof(nums[0]));
	int n = (int) tgamma(len+1);
	int res[n][len];
	// printf("%d", n);
	for(int i = 0; i<len; i++){
		genPerms(nums[i]); 
	}
}









/*
112:

112

121

211


123:

123

132

321

213

312

231


[1,2,3]

i=0 [1,2,3] [2,1,3] [3,2,1]

i=1 [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]

*/


