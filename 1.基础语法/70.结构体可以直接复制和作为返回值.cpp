#include <stdio.h>
#include <string.h>

struct Food{
	char name[20];
	int price;
	char store[32];
};

struct Food add_store(struct Food);

struct Food add_store(struct Food food){
	
	char *p;
	printf("before food.store:%p\n", food.store);
	p = strcpy(food.store,"delicious");
	
	printf("p:%p, food.store:%p\n", p, food.store);
	return food;
}

int main(void){
	struct Food food1 = {
		"ma po dou fu",
		15,
		"no name",
	};
	
	food1 = add_store(food1);
	
	printf("food1.store: %s\n",food1.store);
	return 0;
}