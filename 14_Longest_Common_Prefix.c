/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/



#include <stdio.h>
#include <string.h>
//function to return Longest Common Prefix

/*
char * longestCommonPrefix(char * strs[]){
	// printf("%c", strs[0][3]);
	char lcp[10]; //string storing lcp 
	int i=0;



	while(strs[0][i]!='\0'){
		if(strs[0][i] == strs[1][i] && strs[0][i]== strs[2][i])
		{
			printf("i:%d\n", i);
			lcp[i]=strs[0][i];
			printf("%s\n", lcp);
		}
		else{
			break;
		}
		i++;
	}
	return "";
}
*/


char * longestCommonPrefix(char * strs[], int len){
	int minlen=4, count;
	char lcp[minlen];
	char prev;
	prev=strs[0][0];
	for(int i=0; i<len; i++){
		// printf("%c", strs[i][0]);
		
		for(int j=0; j<minlen; j++){
			
			if(prev!=strs[j][i]){
				return lcp;
			}
			else{
				count++;
			}
			printf("%c\n", strs[j][i]);
		}
		if(count == n){
			lcp=strcnat(lcp, &prev, 1);
		}
	}
	return "";
}

int main(void){
	char * strs[] = {"flower","flox","fxlight"};
	int len = (int) sizeof(strs)/sizeof(strs[0]);
	// printf("%d\n", len);
	printf("%s", longestCommonPrefix(strs, len));
	return 0;
}


/*

flower

flow

flight

i=0, lcp=f
i=1, lcp=fl
i=2, if fails

lcp = fl

lcp at max will be as long as the shortest string
hence we run the while loop only till the shortest string ends

we dont even need to find the shortest string length, 
we simple terminate the loop whenever any string ends(shortest will end first) 
*/