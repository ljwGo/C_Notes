#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *pfp;
	pfp = fopen("hello.txt", "w");
	
	if (pfp == NULL){
		printf("open file error!\n"); //文件打开失败时返回NULL
		exit(EXIT_FAILURE);
	}
	
	fclose(pfp);
	pfp = NULL;
	return 0;
}