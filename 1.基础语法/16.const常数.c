#include <stdio.h>

int main(){
	const int a = 100;
	const int *p = &a;
	
	printf("%d\n", *p);
	
	*p = 1000;  
	printf("*p: %d a: %d\n", *p, a);
	
	return 0;
}