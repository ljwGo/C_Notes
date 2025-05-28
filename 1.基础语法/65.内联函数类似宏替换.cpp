#include <stdio.h>

inline int func(int);

inline int func(int n){
	
	return n * n;
	
	return 0;
}

int main(void){
	int result;
	int n = 9;
	result = func(n + 1);
	printf("%d\n",result);
	return 0;
}

// 在linux下使用 gcc -O filename指令开启内联识别