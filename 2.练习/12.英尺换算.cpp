#include <stdio.h>

/*
int main(void){
	
	int centimeter;
	int inch_nums;
	int inch = 0, foot = 0;
	
	printf("请输入一个正厘米数:");
	scanf("%d", &centimeter);
	
	if (centimeter > 0){
		inch_nums = centimeter * 12 / 30.48;
		foot = inch_nums / 12;
		inch = inch_nums % 12;
		printf("%d %d\n", foot, inch);
	}
	else{
		printf("请输入一个正确的厘米数!");
	}
	
	return 0;
}
*/

int main(void){
	int inch = 0, foot = 0;
	int centimeter = 0;
	double n, feet;
	
	scanf("%d", &centimeter);
	n = (double)centimeter / 30.48;
	foot = (int)n;
	feet = n - foot;
	inch = (int)(feet * 12);
	
	printf("%d %d", foot, inch);
}