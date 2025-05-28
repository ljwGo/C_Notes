#include <stdio.h>

int main(){
	const int a = 100, b = 200;
	const int * const p = &a;
	
	printf("%d\n",*p);
	
	p = &b;
	
	printf("%d\n",*p);
	
	return 0;
}