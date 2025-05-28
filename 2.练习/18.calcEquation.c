#include <stdio.h>
#include <math.h>

void eq(double, double, double, double*, double*);
void gt(double, double, double, double*, double*);
void lt();

int main(void){
	
	double a, b, c, x1, x2;
	
	printf("请输入a，b，c的值：");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (b*b > 4*a*c){
		gt(a, b, c, &x1, &x2);
		printf("x1=%.2f, x2=%.2f", x1, x2);
	}
	else if(b*b == 4*a*c){
		eq(a, b, c, &x1, &x2);
		printf("x1=%.2f, x2=%.2f", x1, x2);
	}
	else{
		lt();
	}

	return 0;
}

void gt(double a, double b, double c, double *x1, double *x2){
	double p, q;
	p = -b/(2.0 * a);
	q = sqrt(b*b - 4*a*c)/(2.0 * a);
	*x1 = p+q; *x2 = p-q;
}

void eq(double a, double b, double c, double *x1, double *x2){
	double p, q;
	*x1 = -b/(2.0 * a);
	*x2 = -b/(2.0 * a);
}

void lt(){
	printf("方程无实数根");
}