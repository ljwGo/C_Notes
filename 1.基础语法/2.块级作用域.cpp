#include <stdio.h>

int main(void){
	int num = 10;
	printf("num before: %d\n", num);
	for (int num = 20; num<22; num++){
		;
	}
	printf("num after: %d\n", num);
	return 0;
}