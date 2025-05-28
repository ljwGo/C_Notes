#include <stdio.h>

int main(void){
//	int *pa = NULL;
//	int a[] = {2,3,4,5,6};
//	int a = 2;
//	pa = &a;
//	printf("%p %d\n", pa, *pa);
//	pa++;
//	printf("%p %d\n", pa, *pa);
//	pa++;
//	printf("%p\n", pa);

//	int a[][3] = {1,2,3,4,5,6,7,8,9};
//	int (*pa)[3] = a;
//	printf("%p, %d, %d\n", pa, *pa, *(*(pa+1)+1));
//	pa++;
//	printf("%p, %d, %d\n", pa, *pa, *(*(pa+1)+1));

	int *pa = NULL;
	int a[3] = {1,2,3};
	pa = a;
	printf("%d,", *(pa+1));
	return 0;
}