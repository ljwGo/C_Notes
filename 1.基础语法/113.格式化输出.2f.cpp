#include <stdio.h>

int main(void){
	
	float a, b;
	int c;
	char d;
	
	scanf("%f %d %c %f", &a, &c, &d, &b);
	printf("%c %d %.2f %.2f", d, c, a, b);
	
	return 0;
}