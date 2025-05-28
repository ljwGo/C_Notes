#include <stdio.h>

void func(int);

void func(int i){
	if (i > 0){
	printf("...\n");
	func(i-1);
	}
	else{
		printf("end");
	}
}

int main(void){
	int a;
	printf("please input a number:");
	scanf("%d",&a);
	func(a);
	return 0;
}