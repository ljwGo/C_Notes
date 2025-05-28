#include <stdio.h>

int main(void){
	
	register int i = 20;
	int *pi = &i;
	
	*pi = 10;
	
	printf("i: %d\n",*pi);
	
	return 0;
}