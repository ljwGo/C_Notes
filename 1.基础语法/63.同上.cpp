#include <stdio.h>
#define FUNC(s) # s

int main(void){
	
	printf(FUNC(hello   %s  %s  world), FUNC(my), FUNC(520));
	
	return 0;
}