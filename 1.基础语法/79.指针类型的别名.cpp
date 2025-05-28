#include <stdio.h>

typedef int *pint;

int main(void){
	
	int c;
	pint a,b;
	a = &c;
	b = a;
	
	return 0;
}