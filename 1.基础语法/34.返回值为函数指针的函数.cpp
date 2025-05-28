#include <stdio.h>

int add(int, int);
int sub(int, int);
// int (*)(int, int) calc(char); 返回值为函数指针类型,错误
int (*calc(char))(int, int); // 正确写法

/* 之所以这样的写法, 是因为编译器从左到右识别语法的 */

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int (*calc(char c))(int, int){
	
	switch (c){
		case '+':return add;
		case '-':return sub;
		default: 0;
	}
}

int main(){
	int a,b,total;
	char sign;
	int (*result)(int, int);
	
	printf("please input a phrase(for example: 2+20):");
	scanf("%d%c%d",&a,&sign,&b);
	result = calc(sign);
	total = result(a,b);
	
	printf("%d\n",total);

	return 0;
}