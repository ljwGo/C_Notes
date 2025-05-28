#include <stdio.h>

char str[] = "hello world";

char *number();

char *number(){
	char *pstr = str;
	return pstr;
}

int main(){
	char *result;
	result = number();
	printf("%s\n",result);
	return 0;
}