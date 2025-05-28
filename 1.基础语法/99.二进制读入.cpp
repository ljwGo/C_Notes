#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	FILE *file;
	char str[20] = "hello world";
	char *pstr;
	int length = strlen(str);
	int num;
	
	pstr = str;
	
	file = fopen("hello.txt", "wb");
	if (file == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	num = fread(pstr, length, 1, file);
	printf("num : %llu\n", num);
	
	fclose(file);
	file = NULL;
	
	return 0;
}