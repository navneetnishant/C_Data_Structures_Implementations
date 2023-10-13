#include <stdio.h>
#include <stdbool.h>


/*
bool checkPalindrome(int x){
	int rev=0;
	int i=0, digits[4];
	// extracting digits from number
	while(x!=0 && i<4){
		digits[i] = x%10;
		x=(int)x/10;
		i++;
	}

	for(int i=0; i<4; i++){
		if(digits[i] != digits[3-i]){
			return false;
		}
		else{
			return true;
		}

	}
}
*/
/*
int main(){
	int x = -121;
	printf("%d\n", checkPalindrome(x));
	return 0;
}

*/




bool isPalindrome(int x) {
    double ans = 0;
    int temp = x;

    while(x>0){
        ans = ans*10 + x%10;
        x = x/10;
    }
    printf("%lf %d\n", ans, temp);
    return temp == ans;
}

int main(void){
	int x = 1221;
	printf("%d", isPalindrome(x));
	return 0;
}


/*
x= 1221 (when x > 0)

temp = x = 1221

x = 1221

x>0 > true > ans = 1.0000, x = 122

x>0 > true > ans = 1.0000*10 + 2 = 12.0000, x = 12

x>0 > true > ans = 12.0000*10 + 2 = 122.0000, x = 1

x>0 > true > ans = 122.0000*10 + 1 = 1221.0000, x = 0


------

x = -1221 (when x < 0)

while loop will not enter and ans = 0.0000

temp == ans > false

*/ 