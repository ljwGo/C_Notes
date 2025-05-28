#include <stdio.h>

int main(void){
	int a, b;
	char sign;
	
	scanf("%d %c %d", &a, &sign, &b);
	
	switch (sign){
		case '+':printf("%d", a + b);break;
		case '-':printf("%d", a - b);break;
		case '*':printf("%d", a * b);break;
		case '/':printf("%d", a / b);break;
		case '%':printf("%d", a % b);break;
		default:
			printf("ERROR");
	}
	
	return 0;
}