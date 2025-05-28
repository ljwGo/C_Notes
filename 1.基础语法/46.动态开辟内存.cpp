#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *pa;
	pa = (int *)malloc(sizeof(int));  //
	*pa = 120;
	printf("%d   %p\n", *pa, pa);
	return 0;
}