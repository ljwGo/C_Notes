#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int *pa;
	pa = (int *)calloc(8,sizeof(int));
	printf("before: %p\n",pa);
	pa = (int *)realloc(pa,1000 * sizeof(int));
	printf("after: %p\n",pa);
	
	free(pa);
	return 0;
}