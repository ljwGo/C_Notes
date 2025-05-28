#include <stdio.h>

int max(int a,int b);

int main(){
	int a,b,c;
	
	printf("please input two number:");
	scanf("%d%d",&a,&b);
	
	c = max(a,b);
	
	printf("bigger number is %d\n");
	
	return 0;
}

int max(int a,int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}