#include <stdio.h>

long long hanoi(int n);

long long hanoi(int n){
	
	static long long result;
	
	if (n > 1){
		result = (2*hanoi(n-1))+1;
	}
	else{
		result = 1;
	}
	
	return result;
}

int main(void){
	int input;
	
	long long result;
	scanf("%d",&input);
	
	result = hanoi(input);
	printf("%lld\n",result);
    
	return 0;
}