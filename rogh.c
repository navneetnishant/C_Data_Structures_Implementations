#include <stdio.h>
#include <string.h>

//finding largest string from a array of strings


int main(void){
	char lcp[4];
	char prev;
	prev='f';
	strncat(lcp, &prev, 1);
	printf("%s\n", lcp);
	prev = 'g';
	strncat(lcp, &prev, 1);
	printf("%s\n", lcp);
	return 0;
}




/*

flower        strs[0][1]

flow              

flight

flies

float          strs[n][1]


first=f    lcp=""

move through each string and check if it matches jth value, 
if it does in all, move the first to lcp

increment i 

move

*/