#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *file;
	int ch;
	
	file = fopen("hello.txt", "r");
	if (file == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	/*while ((ch = fgetc(file)) != EOF){
		printf("%c", ch);
	}*/
	
	do {
		ch = fgetc(file);
		if (ch == EOF){
			printf("%d", ch);
		}
	}
	while (ch != EOF);
	
	putchar('\n');
	
	fclose(file);
	file = NULL;
	return 0;
}