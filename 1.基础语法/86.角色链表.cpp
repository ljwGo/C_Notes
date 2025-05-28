#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MEM_POOL_MAX 1024

int mem_pool_num = 0;
struct Role *mem_pool = NULL;

struct Role {
	int value;
	int age;
	float height;
	char name[32];
	char address[64];
	unsigned long phone;
	struct Role *next;
};

void un_user_char();
void input_role(struct Role *);
struct Role *add_role(struct Role **, int);
void printf_role(struct Role *);
// void release_role(struct Role *);
struct Role *release_role(struct Role*);

void un_user_char(){
	while ('\n' != getchar()){
		;
	}
}

void input_role(struct Role *role){
//	printf("please input your age:");
//	scanf("%d", &role->age);
//	printf("please input your height:");
//	scanf("%f", &role->height);
	printf("please input your name:");
	scanf("%s", role->name);
//	printf("please input yout address:");
//	scanf("%s", role->address);
//	printf("please input your phone:");
//	scanf("%lu", &role->phone);
//	un_user_char();
}

struct Role *add_role(struct Role **family, int value){
	struct Role *previou = NULL, *role = NULL, *current = *family ,*temp = NULL;
	
	if (mem_pool_num > 0){
		role = mem_pool;
		mem_pool = mem_pool->next;
		role->next = NULL;
		mem_pool_num--;
	}
	else{
		role = (struct Role*)malloc(sizeof(struct Role));
	}
	
	input_role(role);
	
	while (current != NULL && current->value < value){
		previou = current;
		current = current->next;
	}
	
	if (previou == NULL){
		temp = *family;
		*family = role;
		//input_role(role);
		role->value = value;
		role->next = temp;
		return *family;
	}
	
	//input_role(role);
	role->next = current;
	previou->next = role;
	role->value = value;
	return *family;
}

void printf_role(struct Role *role){
	
	int count = 1;
	while (role != NULL){
		printf("================%d================\n", count);
		printf("value:    %d\n", role->value);
		printf("name:     %s\n", role->name);
//		printf("age:      %d\n", role->age);
//		printf("height:   %f\n", role->height);
//		printf("address:  %s\n", role->address);
//		printf("phone:    %lu\n", role->phone);
		role = role->next;
		count++;
		putchar('\n');
	}
	if (1 == count){
		printf("please create role before your printf it\n");
	}
	putchar('\n');
}

/*void release_role(struct Role *role){
	
	struct Role *temp = NULL;
	
	while (role != NULL){
		temp = role->next;
		free(role);
		role = temp;
	}
}*/

struct Role *release_role(struct Role *role){
	char name[20];
	int value;
	struct Role *previou = NULL, *temp = NULL, *temp2 = NULL;
	
	printf("please input value or name:");
	scanf("%d%s", &value, name);
	printf("name:%s,  value:%d\n");
	un_user_char();
	
	while (role != NULL){
		if (role->value == value || !strcmp(role->name, name)){
			if (mem_pool_num < MEM_POOL_MAX){
				printf("%d:%s is deleting...\n", role->value, role->name);
				temp = mem_pool;
				mem_pool = role;
				temp2 = role->next;
				role->next = temp;
				mem_pool++;
				role = temp2;
				previou = role;
				continue; //这里要优化
			}
			else{
				printf("%d:%s is deleting...\n", role->value, role->name);
				temp = role->next;
				free(role);
				role = temp;
			}
		}
		previou->next = role;
		role = role->next;
	}
	printf("delete over!\n");
};

int main(void){
	
	char choice;
	int value;
	struct Role *family = NULL;
	
	do{
		printf("please input a choice tell me if you need to create role(y/n):");
		scanf("%c", &choice);
		if ('y' == choice){
			getchar();
			printf("please input a value:");
			scanf("%d", &value);
			family = add_role(&family, value);	
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
	printf_role(family);
	return 0;
}