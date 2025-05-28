#include <stdio.h>

int main(){
	int array[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int (*pa)[4] = array;
	
	printf("*p:%p  *(p+1):%p  *(p+2):%p  \n",*pa,*(pa+1),*(pa+2));
	printf("*p:%d  *(p+1):%d  *(p+2):%d  \n",**pa,**(pa+1),**(pa+2));
	
	return 0;
}