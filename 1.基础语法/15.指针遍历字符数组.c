#include <stdio.h>

int main(){
	char str[] = "hello world";
	char *pa;
	int count = 0;
	
	for (pa=str; *pa++ != '\0';){
		count++;
	}
	printf("%d\n",count);
	
	return 0;
}