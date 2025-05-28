#include <stdio.h>

int main(void){
	
	char boll_a[] = {'A', 'B', 'C'};
	int a, b, c; 
	int different = 0;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if (a == b){
		different = 2;
	}

	if (a == c){
		different = 1;
	}
	
	printf("%c", boll_a[different]);
		
	return 0;
}