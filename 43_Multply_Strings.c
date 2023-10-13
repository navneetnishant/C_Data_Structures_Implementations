#include <stdio.h>
#include <string.h>


int main(void){
	char * num1 = "123", * num2 = "456";
	int carry = 0;
	int mul=0, x1 = 0, x2 = 0;

	// printf("%d", num1[2]-48);
	for(int i=0; i<strlen(num1); i++){
		x1 = (x1*10)+(num1[i]-48);
		x2 = (x2*10)+(num2[i]-48);;
	}
	
	mul = x1*x2;
	
	char digit, res[5];
	int i=0;
	
	while(mul!=0){
		res[5-1-i] = mul % 10 + 48;
		mul=mul/10;
		i++;
	}

	printf("%s", res);
}