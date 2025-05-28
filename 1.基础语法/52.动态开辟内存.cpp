#include <stdio.h>
#include <stdlib.h>

int main(){
	int *pa = NULL;
	int *pb = NULL;
	
	printf("%d\n",sizeof(int *));
	
	pa = (int *)malloc(sizeof(int));
	pb = (int *)malloc(sizeof(int));	
	
	printf("pa:%p  pb:%p\n", pa, pb);
	printf("&pa:%p  &pb:%p\n", &pa, &pb);
	
	free(pa);
	free(pb);
	return 0;
}