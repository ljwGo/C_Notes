#include <stdio.h>

#define SQUARE(x) x*x

int main(void){
	
	int n;
	printf("please input a number:");
	scanf("%d", &n);
	
	printf("square(n) is %d and square(n + 1) is %d\n", SQUARE(n), SQUARE(n + 1)); // => x + 1 * x + 1
	
	return 0;
}