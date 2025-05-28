#include <stdio.h>
#include <math.h>

// 类似统计单词的方法
/*
	标志位preChar,0表示前一个字符不是数字
				  1表示前一个字符是数字
				  默认值为0
	如果前一个字符是数字,下一个字符是非数字,
		preChar由1改为0
		数值位数统计结束,重置为0

	如果前一个字符是非数字,下一个是数字
		preChar由0改为1
		统计数值位数


	需要变量
		preChar
		pi,遍历字符串
		pn,指向一个数的最小位,如"A423"字符串,
			指向的是字符3的地址
		len,统计数值位数,如"A423",统计423为
			3位数
		index,记录是应该存放在数组的那个位置上
*/

//int char2num(char *pch){
//	switch (*pch){
//		case '0':
//			return 0;
//		case '1':
//			return 1;
//		case '2':
//			return 2;
//		case '3':
//			return 3;
//		case '4':
//			return 4;
//		case '5':
//			return 5;
//		case '6':
//			return 6;
//		case '7':
//			return 7;
//		case '8':
//			return 8;
//		case '9':
//			return 9;
//	}
//}

int str2num(char *pch, int len){
	// pch指向数值子序列的尾地址, len数值子序列的长度
	int i, sum = 0;
	for (i=0; i<len; i++, pch--){
		sum += (*pch - 48) * (int)pow(10, i);
	}
	return sum;
}

int main(void){
	
	char str[1024] = {'\0'};
	char *pi = NULL, *pn = NULL;
	
	int preChar = 0, len = 0, index = 0;
	int a[64] = {0};
	
	printf("请输入一串字符,程序会将其中连续数字\
提取出来,保存在数组中");
	gets(str);
	
	// 遍历字符串
	for (pi=str; *pi!='\0'; pi++){
		
		if ('0'<=*pi && *pi<='9'){
		// 下一个字符是数字
		pn=pi;
		
			//  如果上一个字符是非数字
			if (preChar == 0){
				preChar = 1;
			}
			len++;
		}
		else{
			// 如果上一个字符是数字
			if (preChar == 1){
				// 将数值保存在数组中
				a[index++] = str2num(pn, len);
				preChar = 0;
				len=0;
			}
		}
	}
	
	// 最后需要再判断一下len,确保还有数值有没有记录
	if (len){
		a[index] = str2num(pn, len);
	}
	
	for (int i=0; a[i]!=0; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
}
