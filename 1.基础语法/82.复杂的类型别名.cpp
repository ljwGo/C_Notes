#include <stdio.h>

void *(*func1(int, void *(*func2)(int, int)))(int, int);
typedef void *(*P_TO_FUNC)(int, int);

P_TO_FUNC func1(int, P_TO_FUNC);

int main(void){
	
	return 0;
}