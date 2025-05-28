#include <stdio.h>

// 这部分基本忘了
#define PRINTF(format, ...) printf(# format, #__VA_ARGS__)

int main(void){
	
	PRINTF(hello world\n);
	return 0;
}