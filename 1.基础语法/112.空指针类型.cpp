#include <stdio.h>

int main(void){
	
	void *array[10];
	
	int a = 10;
	float b = 20.2;
	long c = 12;
	char d = 'd';
	char string[] = "hello world\n";
	
	array[0] = &a;
	array[1] = &b;
	array[2] = &c;
	array[3] = &d;
	array[4] = string;
	
	return 0;
}