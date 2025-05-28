#include <stdio.h>

#define SQUARE(x) ((x)*(x))

int main(void){
	
	int x;
	printf("please input a number:");
	scanf("%d",&x);
	
	printf("%d square is %d\n", x, SQUARE(x));
	
	return 0;
}