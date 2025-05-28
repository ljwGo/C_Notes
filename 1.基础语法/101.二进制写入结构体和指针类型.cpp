#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

struct Book{
	char name[20];
	char author[20];
	float price;
};

typedef struct Book To_book;

int main(void){
	
	FILE *file;
	To_book library[N];
	
	if ((file = fopen("hello.txt", "wb")) == NULL){
		printf("open file error!n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < N; i++){
		printf("please input information about the book(for example helloworld haha 52.1):\n");
		scanf("%s %s %f", library[i].name, library[i].author, &library[i].price);
	}
	
	fwrite(library, sizeof(To_book), N, file);
	
	fclose(file);
	file = NULL;
	
	if ((file = fopen("hello.txt", "ab")) == NULL){
		printf("open file error!|n");
		exit(EXIT_FAILURE);
	}
	
	int *array[N];
	int a;
	
	for (int i = 0; i < N; i++){
		array[i] = &a;
	}
	
	fwrite(array, sizeof(int *), N, file);
	
	fclose(file);
	file = NULL;
	return 0;
}