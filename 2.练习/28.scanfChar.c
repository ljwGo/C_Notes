#include <stdio.h>
#include <math.h>


int main(void){
	double c;
	int n, i, temp;
	
	printf("������һ����λ��:");
	scanf("%d", &n);
	
	for (i=0; i<4; i++){
		temp = (int)pow(10, 3-i); // tempֵΪ1000��100��10��1.������λ��
		c = n / temp; // c�����洢�ֱ�洢ǧλ����λ��ʮλ�ϵ���
		n %= temp;
		
		putchar(c+48);
		if (3 != i){
			putchar(' ');
		}
	}
	return 0;
}