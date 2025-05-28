#include <stdio.h>

char *pa();

char *pa(){
	char str[] = "hello world";
	char *pstr = str;
	return pstr;
}

int main(){
	char *result;
    result = pa();
    printf("%s\n",result);
    return 0;
}