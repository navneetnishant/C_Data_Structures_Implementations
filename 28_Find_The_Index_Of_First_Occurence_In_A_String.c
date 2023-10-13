#include <stdio.h>
#include <string.h>

int main(void){
	char needle[]="ssad";
	char haystack[]="ssssadodbutsad";
	int nlen = strlen(needle);
	int hlen = strlen(haystack);
	// printf("%s", haystack);
	int count=0, found=-1;
	for(int i=0; i<hlen; i++){
		if(haystack[i] == needle[0]){
			// printf("Entered this if\n");
			// printf("nlen:%d\n", nlen);
			// printf("%c \t %c", haystack[i], haystack[i+nlen-1]);
			for(int j=0; j<nlen; j++){
				// printf("netre");
				if(haystack[i+j] == needle[j]){
					// printf("Entered");
					count++;
				}
				else{
					count=0;
					break;
				}
			}
		}
		if(count == nlen){
			printf("index: \t %d\n", i);
			found = 1;
			break;
		}
	}
	if(found == -1){
		printf("Not found!");
	}
}




/*

char needle[]
char haystack[]

o/p: return index of first occurence of needle in haystack else return -1 if not found

test:

haystack="sadbutsad"
needle="sad"
o/p = 0

haystack="leetcode"
needle="leeto"
o/p = -1

for
	if haystack[i] == needle[0]
		ptr=i;
		for j=i to j = len of needle 
			if  haystack[i] != needle[i]
				break;
			else
				count++
		if count == len(needle)
		return ptr;
		else
			i=i+count;
	

return -1
------------

"sadbutsad
"sad"

s==s
ptr = 0

j=0

*/