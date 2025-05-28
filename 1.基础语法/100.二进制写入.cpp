#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	FILE *file;
	char str[20] = "hello world";
	char *pstr;
	int num;
	
	pstr = str;
	
	file = fopen("hello1.txt", "wb");
	if (file == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	num = fwrite(pstr, 1, 11, file);
	printf("num : %u\n", num);
	
	fclose(file);
	file = NULL;
	
	return 0;
}