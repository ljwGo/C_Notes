#include <stdio.h>
#include <math.h>


int main(void){
	double c;
	int n, i, temp;
	
	printf("请输入一个四位数:");
	scanf("%d", &n);
	
	for (i=0; i<4; i++){
		temp = (int)pow(10, 3-i); // temp值为1000，100，10，1.用来求位数
		c = n / temp; // c用来存储分别存储千位，百位，十位上的数
		n %= temp;
		
		putchar(c+48);
		if (3 != i){
			putchar(' ');
		}
	}
	return 0;
}