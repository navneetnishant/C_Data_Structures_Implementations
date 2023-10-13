#include <stdio.h>
#include <string.h>


//stack using arrays

int push(char * stk, char val, int * tp){
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
	//returning top of stack
	return *tp;

}


int main(void){
	char * s="()[]{}";
	int N = strlen(s);
	int top = -1;
	// printf("%c\n", s[2]);
	char stack[N];

	// stack[0]='C';
	//pushing all characters of the string s to stack
	for(int i=0; i<N; i++){
		push(stack, s[i], &top);	
	}
	

	printf("%c\t %d \n", stack[5], top);

	return 0;
}