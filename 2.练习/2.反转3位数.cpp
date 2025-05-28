#include <stdio.h>
#include <math.h>

/* 反转三位数 */

int main(void){
	/*
	int tail = 0, reverse_n = 0;
	int num;
	
	printf("请输入一个三位正整数:");
	scanf("%d", &num);
	if (100 <= num && num < 1000){
		for (int i = 0; i < 3; i++){
			tail = num / (int)pow(10, i) % 10;
			reverse_n += tail*pow(10, 2-i);
		}
		printf("%d\n", reverse_n);
	}
	else{
		printf("请输入正确的数字!");
	}*/

	int tail = 0, reverse_num[3] = {0}, mark = 0;
	int num;
	
	printf("请输入一个三位正整数:");
	scanf("%d", &num);
	if (100 <= num && num < 1000){
		for (int i = 0; i < 3; i++){
			tail = num / (int)pow(10, i) % 10;
			reverse_num[i] = tail;
		}
		
		for (int i = 0; i < 3; i++){
			if (mark || reverse_num[i] != 0){
				printf("%d", reverse_num[i]);
				mark = 1;
			}
		}
	}
	
	return 0;
}
