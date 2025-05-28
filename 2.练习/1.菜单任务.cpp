#include <stdio.h>
#include <stdlib.h>

// 没注释真的不想看,哎

const char *isCanSort(int [], int);

const char *isCanSort(int a[], int size_t){
	static const char *result_a[] = {"Yes", "No"};
	const char *result = result_a[0]; // 返回的结果
	int element_n = size_t / sizeof(int); // 菜单元素数量
	int max_n = element_n / 3; // 某种菜能出现的最大数量
	int remainder = element_n % 3; // 用于特殊的情况
	int i,j,k,element, hasCheck_l = 0, hasCheck;
	int appear_n; // 用于统计某个菜出现的次数
	int *hasCheck_a = NULL;

	for (i = 0; i < element_n; i++){
		element = a[i];
		appear_n = 0;
		hasCheck = 0;
		for (j = 0; j < hasCheck_l; j++){
			if (element == hasCheck_a[j]){
				hasCheck = 1;
				break;
			}
		} // 判断这个元素是否已经检查过了
		
		if (hasCheck){
			continue;
		} // 如果该元素已经检查过了，那么就不需要得到它的数量了
		
		for (k = i; k < element_n; k++){ // 获取这道菜出现的数量
			if (a[k] == element){
				appear_n++;
			}
		}
		
		if (appear_n <= max_n + 1){ // 判断能否将它排列成间隔两个不同的菜单
			if (appear_n == max_n + 1){
				if (remainder > 0){
					remainder-=1;
				}
				else{
					result = result_a[1];
					break;
				}
			}
		}
		else{
			result = result_a[1];
			break;
		}
		
		hasCheck_l += 1;
		hasCheck_a = (int *)realloc(hasCheck_a, hasCheck_l * sizeof(int));
		hasCheck_a[hasCheck_l - 1] = element;//将该元素加入到被检查的数组之中，避免重复检查
		
	}
	
	free(hasCheck_a);
	return result;
}

int main(void){
	const char *result = NULL;
	int *input_a;
	int input_n;
	
	printf("please input the length of a:");
	scanf("%d", &input_n);
	
	input_a = (int *)malloc(input_n * sizeof(int));

	for (int i = 0; i<input_n; i++){
		scanf("%d", &input_a[i]);
	}
	
	result = isCanSort(input_a, input_n * sizeof(int));
	
	printf("%s", result);
	
	free(input_a);
	input_a = NULL;
	return 0;
}