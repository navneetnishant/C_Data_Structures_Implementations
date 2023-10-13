#include <stdio.h>

#define SIZE 10

int hashFunc(int k){
	return k % 10;
}


int main(void){
	int edges[][2] = {{1,3},{2,3},{4,3}};
	int e = (int) (sizeof(edges)/sizeof(edges[0]));
	int n = e+1;
	// printf("%d", n);
	int hashMap[SIZE];
	for(int i=0; i<SIZE; i++){
		hashMap[i]=0;
	}
	
	int res;
	for(int i=0; i<e; i++){
		hashMap[hashFunc(edges[i][0])]+=1;
		hashMap[hashFunc(edges[i][1])]+=1;
	}

	for(int i=0; i<10; i++){
		// printf("i: %d \t val:%d \n", i, hashMap[i]);
		if(hashMap[i]>1){
			res = hashMap[i];
		}
	}

	printf("res: %d\n", res);

}


/*

  4
  3
1   2
*/