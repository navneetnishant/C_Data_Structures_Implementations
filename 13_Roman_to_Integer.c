#include <stdio.h>
#include <string.h>


int convertToInt(char ch){
	switch(ch){
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			return 0;

	}
}

int romanToInteger(char s[]){
	int len=(int) strlen(s);
	int sum=0, curr=len-2, prev=len-1;
	int prevInt, currInt;

	printf("%s\n", s);
	
	while(curr>=0 || prev>=0){
		prevInt = convertToInt(s[prev]);
		currInt = convertToInt(s[curr]);
		if(prevInt == currInt || prevInt < currInt){
			sum = sum + prevInt + currInt;
		}
		else{
			sum = sum + prevInt - currInt;
		}


		printf("%c \t %c\n", s[prev], s[curr]);
		printf("%d \t %d\n", prevInt, currInt);
		printf("%d\n", sum);
		printf("prev: %d \t curr: %d\n", prev, curr);
		prev = prev - 2;
		curr = curr - 2;
	}


	return sum;
}


int main(void){
	char s[] = "IIII";
	printf("%d\n", romanToInteger(s));
	return 0;
}


/*


LVIII      sum=2    p==c || p < c => sum+p+c    else sum+p-c  if c == \0 sum+p

I 
I 
I 
V 
L p



-----------

MCMXCIV  sum=1993       p==c || p < c => sum+p+c    else sum+p-c  if c == \0 sum+p

p=c+1
c=c+2        while(c<0 && p<0)

V p
I c
C 
X 
M 
C 
M 


if c<0 p is at the first element. we simply add it to the sum

LC

num = 100, prev =0, ans = 0
ans = 0+100 = 100, prev=100

num = 50, prev=100, ans = 100
ans = ans - num = 100 - 50 = 50


*/
