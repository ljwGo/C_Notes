#include <stdio.h>
#include <stdlib.h>
#include "core.c"
#include "model.c"
#include "dataTypedef.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int choice;
	pbook head = NULL;
	char title[64];
	
	// �����ݶ����ļ���ȡ��������
//	if (readNodes(&head) == 0){
//		printf("��û�������ļ�,���߶�ȡ���ݳ���\n");
//	}
	
	// ѭ�������û�����
	do {
		// ��ʾ�˵�
		showMenu();
		
		// �����û�����
		if (recChoice(&choice) == 0){
			printf("��������Ч��ѡ��\n");
			continue;
		}

		switch (choice){
			case 0:
				break;
				
			case 1:
				if (showAllBooks(head) == 0){
					printf("ͼ���б�Ϊ��,��������鼮\n");
					continue;
				}
				break;
				
			case 2:
				if (searchBook(head) == 0){
					printf("ͼ���б�Ϊ��,���߱�Ų��Ϸ�\n");
					continue;
				}
				break;
				
			case 3:
				if (addBook(&head) == 0){
					printf("�½��鼮ʧ��\n");
					continue;
				}
				break;
				
			case 4:
				if (removeBook(&head, title) == 0){
					printf("ɾ��ʧ��\n");
					continue;
				}
				break;
				
			case 5:
				if (clearAllNodes(head) != 1){
					printf("������нڵ����\n");
					continue;
				}
				break;
				
			case 6:
				if (saveNodes(head) == 0){
					printf("�������ݳ���\n");
					continue;
				}
				break;
		}
	}while(choice);
	
	clearAllNodes(head);
	
	system("pause");
	return 0;
}