#include <stdio.h>

void choice_sort(int *, int);

int main(void){
	
	int i;
	int a[10];
	
	printf("请依次输入10个数：");
	for (i=0; i<10; i++){
		scanf("%d", &a[i]);
	}
	
	choice_sort(a, 10);
	
	for (i=0; i<10; i++){
		printf("%d", a[i]);
	}
	
	return 0;
}

void choice_sort(int *a, int n){
	/*
	选择排序
	a是数组首地址，
	n数组元素的个数，
	*/
	int min_index, temp, i, j;
	for (i=0; i<n-1; i++){
		min_index = i;
		for (j=i+1; j<n; j++){
			if (a[j] < a[min_index]){
				min_index = j;
			}
		}
		temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;
	} 
}