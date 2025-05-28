#include <stdio.h>
#include <stdlib.h>

char * new(int n){
	
//	char a[64];
//	return a;
//	返回局部变量,是不可以的,忘了记录下
//	因为函数使用完,栈空间会回收

	return (char *)malloc(n);
}


int main(void){
	
	char *str = new(64);
	
	gets(str);
	
	printf("%s", str);
	
	free(str);
	
	return 0;
}
