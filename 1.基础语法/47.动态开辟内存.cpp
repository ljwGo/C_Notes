#include <stdio.h>
#include <stdlib.h>

int main(){
	int *pa;
	while (1){
		pa = (int *)malloc(sizeof(int));
		free(pa);
	}
	
	return 0;
}