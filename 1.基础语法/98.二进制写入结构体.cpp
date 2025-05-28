#include <stdio.h>
#include <stdlib.h>

struct Book{
	char name[32];
	char author[32];
	float price;
};

typedef struct Book To_book, *P_to_book;

int main(void){
	
	FILE *file;
	P_to_book pbook1;
	int num;
	
	To_book book1 = {
		"hahahaha",
		"emmmmmmm",
		52.2,
	};
	
	pbook1 = &book1;
	
	file = fopen("hello.txt", "a");
	if (file == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}
	
	num = fwrite(pbook1, sizeof(To_book), 1, file);
	printf("num : %llu\n", num);
	
	fclose(file);
	file = NULL;
	
	return 0;
}