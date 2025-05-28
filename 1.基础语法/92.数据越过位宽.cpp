#include <stdio.h>
struct Test {
	int a:2;
	int b:3;
};

typedef struct Test To_test;

int main(void){
	To_test test1;
	test1.a = 1;
	test1.b = 2;
	test1.b = -3;
	
	return 0;
}