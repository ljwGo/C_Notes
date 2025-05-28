#include <stdio.h>
#define PINT int *

int main(void){
	
	PINT age; //
	
	int c;
	PINT a,b;  //
	a = &c;
	b = a;  //[Error] invalid conversion from 'int*' to 'int' [-fpermissive]
	
	return 0;
}