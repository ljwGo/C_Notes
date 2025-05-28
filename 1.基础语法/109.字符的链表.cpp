#include <stdio.h>
#include <stdlib.h>
#define MAX_POOL_NUM 5


int pool_num = 0;

struct Char{
	char ch;
	struct Char *next;
	struct Char *previou;
};

struct Char *top = NULL;
struct Char *pool = NULL;

void add(char);
int add_pool(struct Char *);
void pop();
struct Char *pop_pool();
char get_top();

void add(char ch){
	
	struct Char *pch;
	
	pch = pop_pool();
	
	if (pch == NULL){
		if((pch = (struct Char *)malloc(sizeof(struct Char))) == NULL){
			printf("open mem error!\n");
			exit(EXIT_FAILURE);
		}
	}
	
	pch->next = NULL;
	pch->previou = NULL; // important
	pch->ch = ch;
	
	if (top == NULL){
		top = pch;
	}
	else{
		top->next = pch;
		pch->previou = top;
		top = pch;
	}
}

struct Char *pop_pool(){
	struct Char *pch = NULL;
	
	if (pool != NULL){
		pch = pool;
		pool = pool->next;
		pch->next = NULL;
		pool_num--;
	}
	
	return pch;
}

void pop(){
	
	int result;
	struct Char *pch;
	struct Char *tmp;
	
	tmp = top;
	top = top->previou;
	if (top != NULL){
		top->next = NULL;
		tmp->previou = NULL;
	}
	
	result = add_pool(tmp);
	
	if (result == 0){
		free(tmp);
	}
}

int add_pool(struct Char * tmp){
	if (pool_num < MAX_POOL_NUM){
		tmp->next = pool;
		pool = tmp;
		pool_num++;
		return 1;
	}
	return 0;
}

char get_top(){
	if (top != NULL){
		return top->ch;
	}
	else{
		exit(EXIT_FAILURE);
	}
}

int main(void){
	char strings[64];
	char *pstr;
	int sign = 0;
	
	scanf("%s", strings);
	
	for (pstr=strings; *pstr; pstr++){
		switch (*pstr){
			case '(':
			case '[':
			case '{':
				add(*pstr);break;
			case ')':
				if (top == NULL){
					sign = 1;
					break;
				}
				if (get_top() == '('){
					pop();
				}
				else{
					sign = 1;
				}
				break;

			case ']':
				if (top == NULL){
					sign = 1;
					break;
				}
				if (get_top() == '['){
					pop();
				}
				else{
					sign = 1;
				}
				break;

			case '}':
				if (top == NULL){
					sign = 1;
					break;
				}
				if (get_top() == '{'){
					pop();
				}
				else{
					sign = 1;
				}
				break;
		}
		if (sign){
			printf("error!!!\n");
			break;
		}
	}

	if (!sign){
		printf("successful!!!\n");
	}
}