#include <stdio.h>

int Global_a; //

void a(void);
void b(void);
void c(void);

void a(void){
	Global_a++;
}

void b(void){
	Global_a++;
}

void c(void){
	Global_a++;
}

int main(void){

	a();
	b();
	c();
	c();
	
	int Global_a = 10;
	printf("%d\n",Global_a);
	
	return 0;
}