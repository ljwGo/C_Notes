#include <stdio.h>
#include <math.h>

/*
	���,����(b-a) / �ָ���1000
	���θ�Ϊ����е�, ��Ϊ���
*/

int main(void){
	
	int i;
	// b��������, a��������
	double a, b, interval, area;
	
	// ����һ������ֵΪdouble, �β�Ϊdouble�ĺ���ָ��
	double (*func)(double);
	
	printf("����������ºͻ�������a��b:");
	scanf("%lf %lf", &a, &b);
	
	interval = (a + b) / 1000;
	
	// ָ��sin����
	func = sin;
	area = 0;
	for (i=0; i<1000; i++){
		area += interval * func(interval * i + interval / 2);
	}
	printf("sin: %f\n", area);
	
	// ָ��cos����
	func = cos;
	area = 0;
	for (i=0; i<1000; i++){
		area += interval * func(interval * i + interval / 2);
	}
	
	printf("cos: %f\n", area);
	
	// ָ��exp����
	func = exp;
	area = 0;
	for (i=0; i<1000; i++){
		area += interval * func(interval * i + interval / 2);
	}
	
	printf("exp: %f\n", area);
	
	return 0;
}
