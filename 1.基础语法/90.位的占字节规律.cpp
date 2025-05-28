#include <stdio.h>

int main(void){
	
	struct Test{
		unsigned char a:7;
		unsigned char d:1;
		unsigned char b:2;
		unsigned char c:6;
	};
	
	printf("the sizeof Test is %d\n", sizeof(Test));
	
	return 0;
}