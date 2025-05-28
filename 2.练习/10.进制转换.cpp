#include <stdio.h>

/* 十六进制转换为10进制 */

int main(void){
	
	int error_num, correct_num, ten, bit;
//	printf("请输入一个错误的十进制数[0~153]:");
	scanf("%d", &error_num);
	
	if (0 <= error_num || error_num <= 153){
		ten = error_num / 16;
		bit = error_num % 16;
		correct_num = ten * 10 + bit;
		printf("%d\n", correct_num);
	}
	
	return 0;
}