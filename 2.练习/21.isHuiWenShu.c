#include <stdio.h>

int main(void){
	
	int index, find=0; // index匹配成功后的索引位置，find是否找到的标志位
	char *pstr1, *pstr2, *temp;
	char str1[128], str2[128];
	
	printf("请输入两个字符串:");
	scanf("%s %s", str1, str2);
	
	for (index=0, pstr2=str2; *pstr2 != '\0'; pstr2++){ // 遍历第二个字符串的每个字符
		if (*pstr2 == str1[0]){ // 如果第二个字符串中的当前字符等于第一个字符串的首个字符
			temp = pstr2;
			for (pstr1=str1; *pstr1 != '\0'; pstr1++){ // 依次比较后面的字符是否都相等
				if (*pstr1 != *temp++){
					// 出现有一个字符不相等的情况就不可能匹配了
					break;
				}
		}
			if (*pstr1 == '\0'){ // *pstr1 == '\0'，说明字符串一所有字符在字符串二都一一对应
				find = 1;
			}
		}

		if (find == 1){
			break;
		}
		index++;
	}
	
	if (find){
		printf("字符串一是字符串二的子序列，索引是%d", index);
	}
	else{
		printf("字符串一不是字符串二的子序列");
	}
	return 0;
}
