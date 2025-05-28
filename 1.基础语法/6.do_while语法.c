#include <stdio.h>

int main(){
	// 计算1+2+3+...+100的和
	int i = 1, total = 0;

	do {
		total += i;
		i++;
	}
	while (i <= 100);
	printf("%d\n",total);
	return 0;
}