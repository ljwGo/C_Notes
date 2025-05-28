#include <stdio.h>

int sum(int n);

int sum(int n){
	int result = 0, i = 0;
	for (i; i<=n; i++){
		result += i;
	}
	
	return result;
}

int main(){
	int n,result;
	
	printf("please input a number:");
	scanf("%d",&n);
	
	result = sum(n);
	
	printf("result is %d\n",result);
	
	return 0;
}