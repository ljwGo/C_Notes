#include <stdio.h>

int add(int,int);
int sub(int,int);
int calc(int (*pfunc)(int,int),int a,int b);

int add(int a,int b){
	return a+b;
}

int sub(int a,int b){
	return a-b;
}

int calc(int (*pfunc)(int,int),int a,int b){
	return pfunc(a,b);
}

int main(){
	char c;
	int a,b,result;
	
	printf("please input a phrase:(for example:1+2)");
	scanf("%d%c%d",&a,&c,&b);
	
	switch (c){
		case '+':result = calc(add,a,b);break;
		case '-':result = calc(sub,a,b);break;
	};
	
	printf("%d %c %d = %d",a,c,b,result);
    return 0;
}