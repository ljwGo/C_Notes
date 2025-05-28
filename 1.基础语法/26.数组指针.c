#include <stdio.h>

int main(){
	int array[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int array2[3] = {1,2,3};
	int *x;
	// int *y;
	int (*y)[4];
	x = array2;
	y = array;
	// y = &array[0];
	
	printf("%p,%p\n",array, &array[0][0]);
	
	printf("%p,%p\n",array[0], &array[0][0]);
	
	printf("%d,%d\n",array, &array[0][0]);
	//printf("%d\n",(1,2));
	
	printf("%d\n",*(array2+1));
	printf("%d\n",*(x+1));
	
	printf("%d\n",*(array+1));
	printf("%d\n",*(y+1));
	return 0;
}