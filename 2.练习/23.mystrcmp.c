#include <stdio.h>

int strcmp(char *p1, char *p2){
	int result;
	for (; *p1!='\0' && *p2!='\0'; p1++, p2++){
		// �Ƚ϶�Ӧ�ַ���ascii��ֵ
		result = *p1 - *p2;
		
		// resultֵΪ0,��ʾ��Ӧ�ַ����
		if (result != 0){
			// ��Ϊ0,�����ֵ
			return result;
		}
	}
	// return 0;
	// Ϊ�˱��������ַ����ĳ��ȳ��̲�һ,�̵��ַ����ǳ����ַ�����һ��������
	// ����return 0���������
	return *p1 - *p2;
}

int main(void){
	
	char str1[1024], str2[1024];
	
	printf("�����������ַ���:");
	gets(str1);
	gets(str2);
	
	printf("result: %d", strcmp(str1, str2));
	
	return 0;
}
