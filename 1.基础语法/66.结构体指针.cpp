#include <stdio.h>

int main(void){
	struct Role{
		char name[32];
		int age;
		float height;
	};
	struct Role *prole;
	
	struct Role role1 = {
		"laijianwei",
		20,
		1.75,
	};
	
	// prole = role1;
	prole = &role1;
	
	printf("my name is %s, and my age is %d, my height is %.2f\n", role1.name, role1.age, role1.height);
	printf("my name is %s, and my age is %d, my height is %.2f\n", (*prole).name, (*prole).age, (*prole).height);
	printf("my name is %s, and my age is %d, my height is %.2f\n", prole->name, prole->age, prole->height);
	
	
	return 0;
}