#include <stdio.h>

//int main(){
//	int array[10] = {0,1,2,3,4,5,6,7,8,9};
//	int *p = array;
//	int i;
//
//	for (i = 0, i < 10; i++)
//	{
//		printf("%d\n",*(p+i));
//	}
//	return 0;
//}

int main(){
	int array[3][4] ={
			{0,1,2,3},
			{4,5,6,7},
			{8,9,10,11}
		};
		
	int *p = array;
	int i;
	
	for (i = 0, i < 10; i++)
	{
		printf("%d\n",*(p+i));
	}
	return 0;
}