#include <stdio.h>

// #号是类型说明符吧
#define FUNC(s) # s

int mainn(void){
	
	printf("hello %s\n", FUNC(world));
	
	return 0;
}