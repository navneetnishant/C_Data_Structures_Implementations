#include <stdio.h>

// void swap(int * mtx, int n){
// 	int temp = mtx[i][j];
// 	mtx[i][j] = mtx[j][n-1-i];
// 	mtx[j][n-1-i] = temp;
// }


int main(void){
	int n = 4, temp=0;
	int matrix[][4]={{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
	// int matrix[][5]={{15,14,12,16,2}, {13,3,6,7,3}, {2,4,8,10,4}, {5,1,9,11,5}, {3,7,1,10,7}};
	
	//reverse the matrix rows
	for(int i = 0; i<n/2; i++){
		for(int j=0; j<n; j++){
			temp = matrix[i][j];
			matrix[i][j] = matrix[n-1-i][j];
			matrix[n-1-i][j] = temp;
			// printf("%d\t%d\n", matrix[i][j], matrix[n-1-i][j]);
		}
	}

	//transponse
	for(int i = 0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
			// printf("%d\t", matrix[i][j]);
		}
	}
	
	// printf("\n");
	
	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}


/*

0,0 -> 0,3
0,1 -> 1,3
0,2 -> 2,3
0,3 -> 3,3

1,0 -> 0,2
1,1 -> 1,2


2,0 -> 0,1

3,0 -> 0,0

i,j

i=j, j=4-1-i

swap(a[i][j], a[j][n-1-i])


0,0 => 3,0
3,0 => 3,3

5
2
13
15

5    0,0
2    
13
15
14
11

11
14
15
13
2
5

i=n-1-i , j=j

5,	1,	9,	11
2,	4,	8,	10
13,	3,	6,	7
15,	14,	12,	16


0,0
1,1
2,2
3,3

dont touch the diagonal

stay above the diagonal and swap across the diagonal

i=0, j uptil n
i = 1, j = i+1

0,1 -> 1,0


*/