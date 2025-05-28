#include <stdio.h>
#include <math.h>


int main(void){
	float area, a, b, c, temp, p;
	
	printf("please input triangle length of side:");
	scanf("%f %f %f", &a, &b, &c);
	printf("a=%f, b=%f, c=%f\n", a, b, c);
	
	// 以边长a为最长边
	if (b > a){
		temp = b;
		b = a;
		a = temp;
	}
	
	if (c > a){
		temp = c;
		c = a;
		a = temp;
	}
	
	// 海伦公式area = p(p-a)(p-b)(p-c), 其中p=(a+b+c)/2
	if ((b+c) > a){
		p = (a+b+c) / 2;
		area = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("triangle area: %.2f\n", area);
	}
	
	return 0;
}