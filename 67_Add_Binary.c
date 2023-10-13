#include <stdio.h>
#include <string.h>

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
	char * a = "11";
	char * b = "1011";
	int lenA = strlen(a);
	int lenB = strlen(b);
	int max = lenA > lenB ? lenA : lenB;
	int min = lenA < lenB ? lenA : lenB;
	int res[lenA+1];
	int carry = 0;
	int i = max-1;
	int diff = (lenA - lenB) > 0 ? lenA-lenB : lenB-lenA;
	char stack[min];
	int top = -1;
	// push smaller string in stack


	//store address of smaller string in minStr
	char * min = (min == len A) ? a : b;
	
	for(int i=0; i<min; i++){
			push(stack, minStr[i], &top);
	}
		
	





	// printf("%d", diff);

	// while(i>=0){
	// 	int x1 = a[i]-48; // convert to integer int 1 or 0
	// 	int x2 = b[i]-48;
	// 	// printf("%d\t%d\n", x1, x2);
	// 	printf("%c\t%c\n", a[i-diff], b[i]);
	// 	if(b[i] != '1' && b[i] != '0'){
	// 		printf("%c\n", a[i - diff]);
	// 	}
	// 	// when both bits are 1
	// 	// if(x1 == x2 && x1 == 1){
	// 	// 	carry=1;
	// 	// 	printf("res: 0\t carry: %d\n", carry);
			
	// 	// }
	// 	// else{
	// 	// 	printf("res: %d\n", x1+x2+carry);
	// 	// 	carry=0;
	// 	// }
	// 	i--;
	// }
	
	return 0;
}




/*
"101";
"1011";

*/