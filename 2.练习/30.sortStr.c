#include <stdio.h>
#include <string.h>

int main(void){
	
	char a[5][64];
	char *pa[5];
	char *temp, **min;
	
	int i, j;
	
	printf("请输入5个字符串,程序会对5个字符串进行排序:");
	// 初始化数组
	for (i=0; i<5; i++){
		gets(a[i]);
		pa[i] = a[i]; 
	}
	
	// 选择排序
	for (i=0; i<4; i++){
		min = &pa[i];
		for (j=i+1; j<5; j++){
			if (strcmp(*min, pa[j]) > 0){
				min = &pa[j];
			}
		}
		
		temp = pa[i];
		pa[i] = *min;
		*min = temp;
	}
	
	// 输出排序后的字符串
	printf("排序后的结果为:\n");
	for (i=0; i<5; i++){
		printf("%s\n", pa[i]);
	}
	
	return 0;
}
