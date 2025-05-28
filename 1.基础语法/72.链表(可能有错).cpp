#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Date{
	int year;
	int month;	
	int day;
};

struct Book{
	char title[64];
	char author[32];
	float price;
	char publisher[32];
	struct Date date;
	struct Book *next;
};

struct Book * add_book(struct Book **);
struct Book * add_info(struct Book *);
void show_book(struct Book *);
void release_book(struct Book*);
void unuser_char(void);

struct Book * add_info(struct Book * book){
	
	printf("please input book title:");
	scanf("%s", book->title);
	printf("please input book author:");
	scanf("%s", book->author);
	printf("please input book price:");
	scanf("%f", &book->price);
	printf("please input book publisher:");
	scanf("%s", book->publisher);
	printf("please input book publish date(2021-11-22):");
	scanf("%d-%d-%d", &book->date.year, &book->date.month, &book->date.day);
	
	return book;
}

struct Book * add_book(struct Book ** library){
	struct Book *book = (struct Book*)malloc(sizeof(struct Book));
	if (book == NULL){
		exit(1);
	}
	book = add_info(book);
	book->next = *library;
	*library = book;
	return *library;
};

void show_book(struct Book * library){
	
	int count = 1;
	if (library == NULL){
		printf("no book, please add book before you show it\n");
	}
	
	while (library != NULL){
		printf("===================%d===================\n", count);
		printf("book title:          %s\n",library->title);
		printf("book author:         %s\n", library->author);
		printf("book price:          %.2f\n", library->price);
		printf("book publisher:      %s\n", library->publisher);
		printf("book publish date:   %d-%d-%d\n", library->date.year, library->date.month, library->date.day);
		putchar('\n');
		count++;
		
		library = library->next;
	}
}

void release_book(struct Book * library){
	struct Book *temp;
	while (library != NULL){
		temp = library->next;
		free(library);
		library = temp;
	}
}

void unuser_char(void){
	while (getchar() != '\n'){
		;
	}
}

int main(void){
	
	char choice;
	char choice2;
	struct Book *library = NULL;
	
	do{
		printf("please input a choice(y/n), if you need to add book:");
		scanf("%c", &choice);
		if ('y' == choice){
			library = add_book(&library);
		}
		else if('n' == choice){
			unuser_char();
			break;
		}
		else{
			printf("please input a qualified choice!\n");
		}
		unuser_char();
	}while(1);
	
	do{
		printf("if you need to show your book information(y/n):");
		scanf("%c", &choice2);
		if ('y' == choice2){
			show_book(library);
		}
		else if ('n' == choice2){
			unuser_char();
			break;
		}
		else{
			printf("please input a qualified choice!\n");
		}
		unuser_char();
	}while(1);
	
	release_book(library);
	
	return 0;
}