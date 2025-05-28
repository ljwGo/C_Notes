#include <stdio.h>

int main(){
	int array[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int (*pa)[4] = array;
	
	// printf("(array+1)+2:%d  (array+2)+3:%d \n",((array+1)+2),((array+2)+3));
	
	printf("(array+1)+2:%d  (array+2)+3:%d \n",*(*(array+1)+2),*(*(array+2)+3));
	printf("*(*(pa+1)+2):%d  *(*(pa+2)+3):%d \n",*(*(pa+1)+2), *(*(pa+2)+3));
	
	return 0;
}