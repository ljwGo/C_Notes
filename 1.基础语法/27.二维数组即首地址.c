#include <stdio.h>

int main(){
	int array[3][4] = {0};
	
	printf("array:%p   &array[0][0]:%p\n",array,&array[0][0]);
	
	printf("array+1:%p   &array[1][0]:%p\n",array+1,&array[1][0]);
	
	return 0;
}