#include <stdio.h>
#include <string.h>

int main(void){
	
	char a[5][64];
	char *pa[5];
	char *temp, **min;
	
	int i, j;
	
	printf("������5���ַ���,������5���ַ�����������:");
	// ��ʼ������
	for (i=0; i<5; i++){
		gets(a[i]);
		pa[i] = a[i]; 
	}
	
	// ѡ������
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
	
	// ����������ַ���
	printf("�����Ľ��Ϊ:\n");
	for (i=0; i<5; i++){
		printf("%s\n", pa[i]);
	}
	
	return 0;
}
