#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n;
	int *pa;
	//
	printf("please input how long you want:");
	scanf("%d",&n);
	pa = (int *)malloc(n * sizeof(int));

	//
	for (int i = 0; i < n; i++){
		printf("%d\n",pa[i]);
	}
	
	//
	free(pa);
	return 0;
}