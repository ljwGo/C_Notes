#include <stdio.h>

void un_user_char(void);
void put_str(FILE *);

void un_user_char(void){
	while (getchar() != '\n'){
		;
	}
}

void put_str(FILE *file){
	char str[1024];
	printf("please input a string:");
	scanf("%s", str);
	fputs(str, file);
}

int main(void){
	char choice;
	char filename[20];
	FILE *file;
	
	printf("please input filename:");
	scanf("%s", filename);
	un_user_char();
	
	file = fopen(filename, "w");
	if (file == NULL){
		printf("open file error!\n");
	}
	
	while (1){
		printf("please input if you want to add string(y/n):");
		scanf("%c", &choice);
		un_user_char();
		
		if ('y' == choice){
			put_str(file);
			un_user_char();
		}
		else if ('n' == choice){
			break;
		}
		else {
			printf("please input a qualified cammond!\n");
		}
	}
	
	fclose(file);
	file = NULL;
	
	return 0;
}