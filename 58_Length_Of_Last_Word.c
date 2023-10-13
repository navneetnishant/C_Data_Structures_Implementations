#include <stdio.h>
#include <string.h>

void push(char * stk, char val, int * tp){
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
}

void pop(char * stk, int *tp){
	*tp = *tp - 1;
}

int main(void){
	char * s = "  My  book is  cool    good     ";
	// int len = (int) (sizeof(s)/sizeof(s[0]));
	int len = strlen(s);
	int start=0, end=0;
	// printf("%d\t", len);
	// int i=0;
	for(int i = len-1; i > 0; i--){
		if(s[i] != ' ' && s[i-1] == ' '){
			// printf("%c\n", s[i]);	
			start = i;
			break; 			
		}
		else if(s[i] == ' ' && s[i-1] != ' '){
			end = i;
		}
		// printf("%c\n", s[i]);
	}


	for(int i=start; i < end; i++){
		printf("%c", s[i]);
	}

	return 0;
}