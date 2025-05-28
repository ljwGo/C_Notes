#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *feibonaqie(int **p, int n);
void traverse(int *p, int n);

int *feibonaqie(int **p, int n){  // 创建斐波那契数列
	if (n==1 || n==2){
		*p = (int *)malloc(n*4);
		for (int i = 0; i<n; i++){
			*(*p+i)=1;
		}
		return *p;
	}
	else if (n > 2){
		*p = (int *)malloc(n*4);
		**p = 1;
		*(*p+1) = 1;
		for (int i = 2; i<n; i++){
			*(*p+i) = *(*p+i-1) + *(*p+i-2);
		}
		return *p;
	}
	else{
		return NULL;
	}
}

void traverse(int *p, int n){  //用于遍历的方法
	for (int i=0; i<n; i++){
		printf("%d,", *(p+i));
	}
}


int main(void){
	int n = 0;
	printf("please input length:");
	scanf("%d", &n);
	int *p = NULL;
	
	p = feibonaqie(&p, n);
	traverse(p, n);
	return 0;
}