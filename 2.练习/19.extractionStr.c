#include <stdio.h>
#include <math.h>

// ����ͳ�Ƶ��ʵķ���
/*
	��־λpreChar,0��ʾǰһ���ַ���������
				  1��ʾǰһ���ַ�������
				  Ĭ��ֵΪ0
	���ǰһ���ַ�������,��һ���ַ��Ƿ�����,
		preChar��1��Ϊ0
		��ֵλ��ͳ�ƽ���,����Ϊ0

	���ǰһ���ַ��Ƿ�����,��һ��������
		preChar��0��Ϊ1
		ͳ����ֵλ��


	��Ҫ����
		preChar
		pi,�����ַ���
		pn,ָ��һ��������Сλ,��"A423"�ַ���,
			ָ������ַ�3�ĵ�ַ
		len,ͳ����ֵλ��,��"A423",ͳ��423Ϊ
			3λ��
		index,��¼��Ӧ�ô����������Ǹ�λ����
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
	// pchָ����ֵ�����е�β��ַ, len��ֵ�����еĳ���
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
	
	printf("������һ���ַ�,����Ὣ������������\
��ȡ����,������������");
	gets(str);
	
	// �����ַ���
	for (pi=str; *pi!='\0'; pi++){
		
		if ('0'<=*pi && *pi<='9'){
		// ��һ���ַ�������
		pn=pi;
		
			//  �����һ���ַ��Ƿ�����
			if (preChar == 0){
				preChar = 1;
			}
			len++;
		}
		else{
			// �����һ���ַ�������
			if (preChar == 1){
				// ����ֵ������������
				a[index++] = str2num(pn, len);
				preChar = 0;
				len=0;
			}
		}
	}
	
	// �����Ҫ���ж�һ��len,ȷ��������ֵ��û�м�¼
	if (len){
		a[index] = str2num(pn, len);
	}
	
	for (int i=0; a[i]!=0; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
}
