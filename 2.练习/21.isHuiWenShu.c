#include <stdio.h>

int main(void){
	
	int index, find=0; // indexƥ��ɹ��������λ�ã�find�Ƿ��ҵ��ı�־λ
	char *pstr1, *pstr2, *temp;
	char str1[128], str2[128];
	
	printf("�����������ַ���:");
	scanf("%s %s", str1, str2);
	
	for (index=0, pstr2=str2; *pstr2 != '\0'; pstr2++){ // �����ڶ����ַ�����ÿ���ַ�
		if (*pstr2 == str1[0]){ // ����ڶ����ַ����еĵ�ǰ�ַ����ڵ�һ���ַ������׸��ַ�
			temp = pstr2;
			for (pstr1=str1; *pstr1 != '\0'; pstr1++){ // ���αȽϺ�����ַ��Ƿ����
				if (*pstr1 != *temp++){
					// ������һ���ַ�����ȵ�����Ͳ�����ƥ����
					break;
				}
		}
			if (*pstr1 == '\0'){ // *pstr1 == '\0'��˵���ַ���һ�����ַ����ַ�������һһ��Ӧ
				find = 1;
			}
		}

		if (find == 1){
			break;
		}
		index++;
	}
	
	if (find){
		printf("�ַ���һ���ַ������������У�������%d", index);
	}
	else{
		printf("�ַ���һ�����ַ�������������");
	}
	return 0;
}
