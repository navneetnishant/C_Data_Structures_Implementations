#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//stack using arrays

// pushing elements on stack
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
	//returning top of stack

}

//popping elements from stack
void pop(char * stk, int * tp){
	if(*tp == -1){
		//stack empty, cant pop
		printf("underflow!");
	}
	else{
		*tp = *tp - 1;
	}
}


//find complementary of brackets '{' => '}'
char complement(char val){
	switch(val){
		// case '{':
		// 	return '}';
		// case '[':
		// 	return ']';
		// case '(':
		// 	return ')';
		case '}':
			return '{';
		case ']':
			return '[';
		case ')':
			return '(';
		default:
			return '1';
	}

}

int main(void){
	char * s="[({)]}";
	int N = strlen(s);
	int top = -1;
	int ans = -1;
	// printf("%c\n", s[2]);
	char stack[N];

	// stack[0]='C';
	//pushing all characters of the string s to stack
	for(int i=0; i<N; i++){
		if(s[i] == '{' || s[i] == '[' || s[i] == '('){
			push(stack, s[i], &top);
		}
		else if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
			if(complement(s[i]) == stack[top]){
				pop(stack, &top);
			}
		}
	}
	if(top == -1){
		printf("Valid");
	}
	else{
		printf("Invalid");
	}
	return 0;
}


/*
{[()]}

stack
(
[
{

*/