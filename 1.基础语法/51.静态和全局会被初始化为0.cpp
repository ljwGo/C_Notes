#include <stdio.h>
#include <stdlib.h>

int global_var_uninit;
int global_var_init = 1024;

void func(void);

void func(void){
	;
}

int main(void){
	int local_var_uninit;
	int local_var_init = 111;
	
	static int static_var_uninit;
	static int static_var_init = 512;
	
	char *str1_before = "You are right!";
	char *str2_after = "hello world";
	
	int *pa = (int *)malloc(sizeof(int));
	
	printf("addr of local_var_uninit is: %p\n", &local_var_uninit);
	printf("addr of local_var_init is: %p\n", &local_var_init);
	printf("addr of pa is: %p\n", pa);
	printf("addr of static_var_uninit is: %p\n", &static_var_uninit);
	printf("addr of global_var_uninit is: %p\n", &global_var_uninit);
	printf("addr of static_var_init is: %p\n", &static_var_init);
	printf("addr of global_var_init is: %p\n", &global_var_init);
	printf("addr of str2_after is: %p\n", str2_after);
	printf("addr of str1_before is: %p\n", str1_before);
	printf("addr of func is: %p\n", func);
	
	return 0;
}