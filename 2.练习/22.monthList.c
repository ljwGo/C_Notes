#include <stdio.h>

int main(void){
	
	// 让指针本生是常量
	char * const monthList[12]={
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int n;
	
	printf("请输入月份号,程序会输出对应的月份名称:");
	scanf("%d", &n);
	
	// 必须是有效数字
	if (1<= n && n <= 12){
		printf("%s", monthList[n-1]);
	}
	
	return 0;
}
