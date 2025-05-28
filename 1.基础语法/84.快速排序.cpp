#include <stdio.h>

void quick_sort(int [10], int, int);

void quick_sort(int array[10], int start, int end){
	if (start == end){
		return;
	}
	
	int center, i, j, temp;
	i = start;
	j = end;
	center = array[(start+end) / 2];
	
	do{
		while (array[i] < center){
			i++;
		}
		
		while (array[j] > center){
			j--;
		}
		
		if (i <= j){
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
		if (j < start){
			j = start;
		}
		if (i > end){
			i = end;
		}
	}
	while (i <= j);
	
	quick_sort(array, start, j);
	quick_sort(array, i, end);
	
	
}

int main(void){
	int array[] = {1,2,3,4,5,8,5,1,6,5};
	
	int end_index = sizeof(array) / sizeof(int);
	quick_sort(array, 0, end);
	
	for (int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	return 0;
}