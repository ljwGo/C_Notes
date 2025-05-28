#include <stdio.h>

int main(void){
	
	float f_temperature;
	
	printf("please input a f_temperature:");
	scanf("%f", &f_temperature);
	
	printf("c_temperature: %.2f\n", (f_temperature-32)*5/9);
}