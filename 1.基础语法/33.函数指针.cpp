#include <stdio.h>

char *my_str();

char *my_str(){
	return "hello world";
}

int main(){
	char *(*pa)();
	pa = my_str;
	
	printf("pa:%p  my_str:%p\n",pa,my_str);
	return 0;	
}