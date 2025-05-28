#include <stdio.h>

int main(void){
	int n = -10, m = 23;
	int a = -23, b = 10;
	printf("%d %d \n", m / n, m % n);  // 取余的规律是，如果被除数和除数只有一个为负数，那么商一定为负数；余数的值根据被除数的正负决定
	printf("%d %d \n", a / b, a % b);
	
	m = -10, n = 23;
	a = 10, b = -23;
	printf("%d %d \n", m / n, m % n);
	printf("%d %d \n", a / b, a % b);
	
	m = -17, n = -10;  // 当被除数和除数都为负数时，它的商一定是正数，它的余数一定是负数
	a = -10, b = -23;
	printf("%d %d \n", m / n, m % n);
	printf("%d %d \n", a / b, a % b);
	return 0;
}