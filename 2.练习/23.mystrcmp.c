#include <stdio.h>

int strcmp(char *p1, char *p2){
	int result;
	for (; *p1!='\0' && *p2!='\0'; p1++, p2++){
		// 比较对应字符的ascii码值
		result = *p1 - *p2;
		
		// result值为0,表示对应字符相等
		if (result != 0){
			// 不为0,输出差值
			return result;
		}
	}
	// return 0;
	// 为了避免两个字符串的长度长短不一,短的字符串是长的字符串的一个子序列
	// 不用return 0而是下面的
	return *p1 - *p2;
}

int main(void){
	
	char str1[1024], str2[1024];
	
	printf("请输入两个字符串:");
	gets(str1);
	gets(str2);
	
	printf("result: %d", strcmp(str1, str2));
	
	return 0;
}
