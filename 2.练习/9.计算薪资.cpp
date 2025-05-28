#include <stdio.h>

int main(void){
	
	int work_years, work_hours, over_hours, per_price;
	float salary;
	scanf("%d %d", &work_years, &work_hours);
	
	if (0 <= work_years && 0 <= work_hours){
		if (work_years < 5){
			per_price = 30;
		}
		else{
			per_price = 50;
		}
		over_hours = work_hours % 50;
		salary = per_price*work_hours + over_hours*1.5*per_price;
		printf("%.2f", salary);
	}

//	int a = 10;
//	float b = 2.2;
//	float sum;
//
//	sum = a * b;
//
//	printf("%f", sum);
	
	return 0;
}