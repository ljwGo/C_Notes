#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *fp;
	int c;
	
	if ((fp = fopen("hello.txt", "w")) == NULL){
		printf("open the file error!\n");
		exit(EXIT_FAILURE);
	}
	
	fputs("hello world", fp);
	
	while (1){
		c = fgetc(fp);
		if (c == '\0'){
			printf("find the char \\0\n");
			break;
		}
	}
	
	return 0;
}