#include <stdio.h>
#include <stdlib.h>

struct Test{
	int num;
};

struct Test *func(){
	return NULL;
}

int main(void){
	
	struct Test *p;
	p = func();
	
	printf("%d\n", p==NULL);
	printf("%d\n", 1==1);
	
	return 0;
}