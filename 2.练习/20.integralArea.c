#include <stdio.h>
#include <math.h>

/*
	间隔,积分(b-a) / 分割数1000
	矩形高为间隔中点, 底为间隔
*/

int main(void){
	
	int i;
	// b积分上限, a积分下限
	double a, b, interval, area;
	
	// 定义一个返回值为double, 形参为double的函数指针
	double (*func)(double);
	
	printf("请输入积分下和积分上限a和b:");
	scanf("%lf %lf", &a, &b);
	
	interval = (a + b) / 1000;
	
	// 指向sin函数
	func = sin;
	area = 0;
	for (i=0; i<1000; i++){
		area += interval * func(interval * i + interval / 2);
	}
	printf("sin: %f\n", area);
	
	// 指向cos函数
	func = cos;
	area = 0;
	for (i=0; i<1000; i++){
		area += interval * func(interval * i + interval / 2);
	}
	
	printf("cos: %f\n", area);
	
	// 指向exp函数
	func = exp;
	area = 0;
	for (i=0; i<1000; i++){
		area += interval * func(interval * i + interval / 2);
	}
	
	printf("exp: %f\n", area);
	
	return 0;
}
