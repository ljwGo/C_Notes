#include <stdio.h>

int main(){
	const int a = 100;
	int b = 200;
	const int *p = &a;
	
	printf("%d\n",*p);
	
	p = &b;
	
	printf("%d\n",*p);
	
	b = 2000; // b±»¸ÄÁË
	
	printf("%d\n",*p)
	
	return 0;
}