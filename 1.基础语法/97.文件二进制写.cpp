#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *file;
	int a = 67, *pa = &a;
	int ch;
	
	file = fopen("hello.txt", "wb");
	if (file == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	fwrite(pa, 4, 1, file);
	
	fclose(file);
	file = NULL;
	
	file = fopen("hello.txt", "r");
	if (file == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	ch = fgetc(file);
	printf("%c\n", ch);
	
	fclose(file);
	file = NULL;
	return 0;
}