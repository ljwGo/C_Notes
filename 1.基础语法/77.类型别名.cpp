#include <stdio.h>

typedef int my_int,*pmy_int;

int main(void){
	
	my_int i;
	pmy_int pi;
	
	pi = &i;
	
	printf("p:%p\n", pi);
	
	return 0;
}