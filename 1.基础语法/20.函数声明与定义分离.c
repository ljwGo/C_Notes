#include <stdio.h>

int number();

int main(){
	int i,j;
	i = number();
	printf("\n");
	j = number();
	
	printf("i : %d, j : %d\n",i,j);
	
	return 0;
}

int number(){
	return 10;
}