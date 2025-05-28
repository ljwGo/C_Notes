#include <stdio.h>

void hanoi(int);

void hanoi(int i, char start, char end, char temp){
	if (i > 1){
		hanoi(i-1, start, temp, end);
		printf("%c -> %c\n",start,end);
		hanoi(i-1, temp, end, start);
	}
	else{
		//printf("%c -> %c\n",start,temp);
		printf("%c -> %c\n",start,end);
		//printf("%c -> %c\n",temp,end);
	}
}

int main(void){
	int a;
	long result;
	printf("please input a number:");
	scanf("%d",&a);
	hanoi(a, 'X', 'Z', 'Y');
	return 0;
}