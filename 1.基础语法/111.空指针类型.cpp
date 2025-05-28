#include <stdio.h>

int main(void){
	
	void *array[10];
	int a = 10;
	float b = 1.2;
	long c = 24;
	char str[20] = "hello world";
	
	array[0] = &a;
	array[1] = &b;
	array[2] = &c;
	array[3] = str;

	// printf("%d\n", *array[0]);
	printf("%d\n", *(int *)array[0]);
	
	// printf("%f\n", *array[1]);
	printf("%f\n", *(float *)array[1]);
	
	// printf("%s\n", *array[3]);
	printf("%s\n", (char *)array[3]);
	return 0/
}