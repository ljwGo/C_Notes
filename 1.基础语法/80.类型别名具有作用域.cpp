#include <stdio.h>

int main(void){
	// 类型别名具有作用域
	{
		typedef int *pint;
	}
	
	{
		int c;
		pint a, b;
		a = &c;
		b = a;
	}
	return 0;
}