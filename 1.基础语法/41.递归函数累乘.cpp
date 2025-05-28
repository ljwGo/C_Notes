#include <stdio.h>

long func(int);

long func(int i){
	if (i < 1){
		return 1;
	}
	else{
		return i * func(i-1);
	}
}

int main(void){
	int a;
	long result;
	printf("please input a number:");
	scanf("%d",&a);
	result = func(a);
	
	printf("result is %ld\n",result);
	return 0;
}