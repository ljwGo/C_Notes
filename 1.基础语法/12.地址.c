#include <stdio.h>

int main(){
	int array[5] = {1,2,3,4,5};
	int i;
	
	for (i=0; i<5; i++){
		printf("%d address is %p\n",i,&array[i]);
		
	}
	
	return 0;
}