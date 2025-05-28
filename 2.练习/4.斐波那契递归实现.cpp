#include <stdio.h>

int feibonaqi(int n);

int feibonaqi(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	else{
		return feibonaqi(n-1) + feibonaqi(n-2);
	}
}


int main(void){
	int n = 0, res = 0;
	printf("please input a number:");
	scanf("%d", &n);
	res = feibonaqi(n);
	printf("No.%d:  %d", n, res);	
	return 0;
}