#include <stdio.h>
#include <stdlib.h>

char * new(int n){
	
//	char a[64];
//	return a;
//	���ؾֲ�����,�ǲ����Ե�,���˼�¼��
//	��Ϊ����ʹ����,ջ�ռ�����

	return (char *)malloc(n);
}


int main(void){
	
	char *str = new(64);
	
	gets(str);
	
	printf("%s", str);
	
	free(str);
	
	return 0;
}
