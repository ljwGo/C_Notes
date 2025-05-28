#include <stdio.h>
#include <string.h>

union Test{
	int a;
	float b;
	long long c;
	char str[16];
};

typedef union Test to_Test;

int main(void){
	to_Test test1;
	
	test1.a = 10;
	strcpy(test1.str, "hello world");
	test1.b = 12.2;
	test1.c = 15;
	
	printf("test.a is: %d\n", test1.a);
	printf("test.b is: %f\n", test1.b);
	printf("test.c is: %ll\n", test1.c);
	printf("test.c is: %s\n", test1.str);
	
	return 0;
}