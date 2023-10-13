#include <stdio.h>

int main(){
	int digits[] = {1,9,9,9};
	int val=1;
	int len = (int) (sizeof(digits)/sizeof(digits[0]));
	// printf("%d", len);
	int carry = 0, prevCarry = 0;
	for(int i=len-1; i>=0; i--){
		//last element
		if(val>0){
			carry=(int) (digits[i]+val+prevCarry)/10; //quotient
			digits[i] = (digits[i]+val+prevCarry)%10; //remainder
			prevCarry=carry;
			val=0;
		}
		else{
			carry=(int) (digits[i]+val+prevCarry)/10; //quotient
			digits[i] = (digits[i]+val+prevCarry)%10;
			prevCarry=carry;	
		}
		
	} 


	for(int i=0; i<len; i++){
		printf("%d", digits[i]);
	}
}

/*
prevCarry = 1
carry = 1

1,9,9,0

*/