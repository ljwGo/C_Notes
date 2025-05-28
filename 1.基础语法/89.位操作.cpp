#include <stdio.h>

int main(void){
	
	struct Test{
		unsigned int a:1;
		unsigned int b:1;
		unsigned int c:3;	
	};
	
	printf("the size of Test is %d\n", sizeof(struct Test));
	return 0;
}