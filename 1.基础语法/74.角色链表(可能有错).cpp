#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Role {
	int age;
	float height;
	char name[32];
	char address[64];
	unsigned long phone;	
	struct Role *next;
};

void un_user_char();
void input_role(struct Role *);
struct Role *add_role(struct Role **);
void printf_role(struct Role *);
void release_role(struct Role *);

void un_user_char(){
	while ('\n' != getchar()){
		;
	}
}

void input_role(struct Role *role){
	printf("please input your age:");
	scanf("%d", &role->age);
	printf("please input your height:");
	scanf("%f", &role->height);
	printf("please input your name:");
	scanf("%s", role->name);
	printf("please input yout address:");
	scanf("%s", role->address);
	printf("please input your phone:");
	scanf("%lu", &role->phone);
}

struct Role *add_role(struct Role **family){ //
	struct Role *temp = *family;
	
	if (temp == NULL){ //
		*family = (struct Role *)malloc(sizeof(struct Role));
		input_role(*family);
		return *family;
	}
	
	while (temp->next != NULL){ //
		temp = temp->next;
	}
	
	temp->next = (struct Role *)malloc(sizeof(struct Role));
	input_role(temp->next);
	return *family;
}

void printf_role(struct Role *role){
	
	int count = 1;
	while (role != NULL){
		printf("================%d================\n", count);
		printf("name:     %s\n", role->name);
		printf("age:      %d\n", role->age);
		printf("height:   %f\n", role->height);
		printf("address:  %s\n", role->address);
		printf("phone:    %lu\n", role->phone);
		role = role->next;
		count++;
		putchar('\n');
	}
	if (1 == count){
		printf("please create role before your printf it\n");
	}
	putchar('\n');
}

void release_role(struct Role *role){
	
	struct Role *temp = NULL;
	
	while (role != NULL){
		temp = role->next;
		free(role);
		role = temp;
	}
}
int main(void){
	
	char choice;
	struct Role *family = NULL;
	
	do{
		printf("please input a choice tell me if you need to create role(y/n):");
		scanf("%c", &choice);
		if ('y' == choice){
			family = add_role(&family);	
		}
		else if ('n' == choice){
			un_user_char();
			break;
		}
		else {
			printf("%c is a unqualified command! please input again!\n", choice);
		}
		un_user_char();
	}while(1);
	
	do {
		printf("please input a choice tell me if you need to printf all user infomation(y/n):");
		scanf("%c", &choice);
		if ('y' == choice){
			printf_role(family);
		}
		else if ('n' == choice){
			un_user_char();
			break;
		}
		else {
			printf("%c is a unqualified command! please input again!\n", choice);
		}
		un_user_char();
	}while(1);
	
	release_role(family);
	return 0;
}