#include <stdio.h>
#include <math.h>

int main(void){
	
	unsigned int three_n, reverse_n=0, temp, tail_n;
	
	printf("please input a three number:");
	scanf("%u", &three_n);
	
	temp = three_n;
	for (int i=0; i<3; i++){
		tail_n = temp % 10;
		temp /= 10;
		reverse_n += tail_n * (unsigned int)pow(10, 2-i);
	}
	printf("reverse_n: %u", reverse_n);
	return 0;
}