#include <stdio.h>
#include <string.h>

int main(){
	char str[] = "hello world";
	printf("%s\n",str);
	
	printf("%d\n",sizeof(str));  // 12
	
	printf("%d\n",strlen(str));  // 11
	return 0;
}