/* Hash Function Methods */


/* 
Hashing - Division Method 

h(x) = x % M;
best to choose 'M' to be a prime number

*/



/* 
Hashing - Multiplication Method
h(k) = (k*A % 1)*m

A => 0 < A < 1 (best value of A: (sqrt 5 -1)/2 = 0.61800339887)

k => key

m => size of hashmap

*/

/* 
Hashing - Mid-Square Method

square the key => k*k

take r digits from the middle of k*k => s

h(k) = s

eg
keys 1234 and 5642 if mapped on hashmap of size 100

k*k=1234*1234 = 1522756 => h(1234) = 27
k*k=5642*5642 = 31832164 => h(5642) = 21 
(3rd and 4th digit is chosen from the last)

since size of hashmap = 100
so two digits are enough for index, r=2


*/


/* 
Folding Method
keys 5678, 321, and 34567
hashmap size 100

we break the numbers in two digit parts except the last digit 

5678 => 56+78 => 134 => drop the last carry => h(5678) = 34
321 => 32+1 => h(321)=33 
34567 => 34+56+7 => h(k)=97

*/

#include <stdio.h>
#include <math.h>

// hash function using Multiplication Method
int hashFunc(int k, int m){
	double A = 0.6180033;
	double temp;
	double kA =k*A;
	printf("%f", kA);
	double fraction = modf(kA, &temp); 
	printf("%f", fraction);
	return remainder((k*A),1)*m;
}

int main(void){
	int x = 12345;
	int m = 1000;
	int hashMap[m];
	hashFunc(x, m);
}
