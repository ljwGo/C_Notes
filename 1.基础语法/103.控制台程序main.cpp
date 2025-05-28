#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ONE_GET_MAX 1024

int main(int argc, char *argv[]){
	FILE *file = NULL, *file_cpy = NULL;
	
	if ((file = fopen(argv[1], "rb")) == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	if ((file_cpy = fopen(argv[2], "wb")) == NULL){
		printf("create file error!\n");
		exit(EXIT_FAILURE);
	}
	
	char *pstr = (char *)malloc(sizeof(1024));
	
	while (!feof(file)){
		fread(pstr, ONE_GET_MAX ,1 ,file);
		fwrite(pstr, strlen(pstr), 1, file_cpy);
	}
	
	fclose(file);
	fclose(file_cpy);
	file = NULL;
	file_cpy = NULL;
	return 0;
}