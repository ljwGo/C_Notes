#include <stdio.h>

int main(){
	char first[6];
	char other[10];
	
	printf("input first:");
	scanf("%c%c_dsb",first);
	printf("first : %s\n",first);
	
	getchar();
	
	printf("input second:");
	scanf("%s",other);
	printf("other : %s\n",other);
	return 0;
}
