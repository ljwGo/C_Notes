#include <stdio.h>
#define FUNC(a) # a

int main(void){
	
	printf(FUNC(hello %s %d\n), FUNC(world), 250);
	
	return 0;
}