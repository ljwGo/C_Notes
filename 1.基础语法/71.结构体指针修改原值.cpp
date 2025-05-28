#include <stdio.h>
#include <string.h>

struct Food{
	int price;
	char name[64];
	char store[32];
};

struct Food * add_store(struct Food *);

struct Food * add_store(struct Food * food){
	
	strcpy(food->store, "delicious");

	return food;
}

int main(void){
	struct Food food1 = {
		20,
		"luo si fen",
		"hello",
	};
	
	struct Food *food = &food1;
	
	add_store(food);
	
	return 0;
}