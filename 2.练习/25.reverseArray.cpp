#include <stdio.h>

int main(void){
	
	int temp, i, size;
	int a[9];
	
	printf("请输入数组的大小：");
	scanf("%d", &size);
	
	printf("请输入%d个数：\n", size);
	for (i=0; i<size; i++){
		scanf("%d", &a[i]);
	}
	
	// 逆序，将对应位交换，0和最后一位，1和倒数第二位
	for (i=0; i<size/2; i++){
		temp = a[i];
		a[i] = a[size-i-1];
		a[size-i-1] = temp;
	}
	
	for (i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
}