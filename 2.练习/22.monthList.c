#include <stdio.h>

int main(void){
	
	// ��ָ�뱾���ǳ���
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
	
	printf("�������·ݺ�,����������Ӧ���·�����:");
	scanf("%d", &n);
	
	// ��������Ч����
	if (1<= n && n <= 12){
		printf("%s", monthList[n-1]);
	}
	
	return 0;
}
