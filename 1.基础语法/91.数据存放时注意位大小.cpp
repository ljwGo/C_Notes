#include <stdio.h>

int main(void){
	
	struct Test{
		char a:2;
		char b:3;
		unsigned char c:6;
		unsigned char d:7;
	};
	
	typedef struct Test To_Test;
	
//	To_Test test1 = {
//		'h',
//		'i',
//		'j',
//		'k',
//	};

//	To_Test test1 = {
//		3,
//		7,
//		3,
//		7,
//	};

	To_Test test1 = {
		'h',
		'i',
		'j',
		'k',
	};
	
	printf("a:%c, b:%c, c:%c, d:%c\n", test1.a, test1.b, test1.c, test1.d);
	printf("a:%d, b:%d, c:%d, d:%d\n", test1.a, test1.b, test1.c, test1.d);
	
	return 0;
}