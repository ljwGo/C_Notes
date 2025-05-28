#include <stdio.h>

struct Role{
	char name[32];
	int age;
	float height;
};

void printf_info(struct Role);

void printf_info(struct Role role){
	
	printf("name is:%s\n", role.name);
	printf("age is:%d\n", role.age);
	printf("height is:%f\n", role.height);
}

int main(void){
	
	struct Role role1 = {
		"hahaha",
		20,
		1.75,
	};
	
	printf_info(role1);
	return 0;
}