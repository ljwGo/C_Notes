/*
	���ĵĳ����߼�
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dataTypedef.c"


void showMenu(){
	// ����:�г����ܲ˵�
	printf("+--------------------------------------+\n");
	printf("|\t\tͼ�����ϵͳ\t\t|\n");
	printf("+--------------------------------------+\n");
	printf("1 �г�����ͼ��\n");
	printf("2 ��ѯָ��ͼ��\n");
	printf("3 ������¼\n");
	printf("4 ɾ����¼\n");
	printf("5 ���ͼ���б�\n");
	printf("6 �����޸�\n");
	printf("0 �˳�\n");
	printf("������ѡ��Ĺ���:\n");
	putchar('\n');
}

int recChoice(int *pChoice){
	// ����:�����û������ѡ��
	// ����:pChoice,�洢ѡ��ֵ�����ĵ�ַ
	// ����ֵ:������Ϸ�,����0; �Ϸ�����1
	int x;
	scanf("%d", &x);
	
	// ��ѡ��Ϸ��Խ���Ч��
	if (x<0 || x>6){
		// ���Ϸ�
		return 0;
	}
	*pChoice = x;
	return 1;
}

int showAllBooks(pbook head){
	// ����:��ʾ�����鼮
	// ����:head ����ͷָ��
	// ����ֵ:0��ʾͷָ��Ϊ��,�޷�����; 1��ʾ���Ա���
	if (head == NULL)
		return 0;
	
	int i;
	pbook iNode;
	
	printf("---------------�����鼮---------------\n");
	for (i=1, iNode=head; iNode!=NULL; iNode=iNode->next){
		printf("���:%d ����%s\n", i++, iNode->title);
	}
	putchar('\n');
}

int searchBook(pbook head){
	// ����:����ĳ����ŵ��鼮����ϸ��Ϣ
	// ����:head ����ͷָ��
	// ����ֵ:0��ʾͷָ��Ϊ�ջ��Ų��Ϸ�,�޷�����; 1��ʾ�ҵ�; -1��ʾ�Ҳ���
	int ordinal, i;
	pbook iNode;
	
	// ������
	printf("��������:");
	scanf("%d", &ordinal);
	
	if (head == NULL || ordinal < 1)
		return 0;
	
	// ��������,�ҵ���Ӧ�ı���鼮
	for (i=1, iNode=head; iNode!=NULL; iNode=iNode->next, i++){
		if (i == ordinal){
			printf("-------------�ҵ��Ȿ����!!!-------------\n");
			printf("����: %s\n", iNode->title);
			printf("����: %s\n", iNode->author);
			printf("ʱ��: %s\n", iNode->time);
			printf("�۸�: %f.2\n", iNode->price);
			putchar('\n');
			return 1;
		}
	}
	putchar('\n');
	return 0;
}

int formatTime(char *timeArray, int year, int month, int day){
	/*  
	����:�������ո�ʽ��,�洢����book�ṹ���time��Ա��
	����:timeArray��Ÿ�ʽ��ʱ��������ַ
	����ֵ:0��ʾʱ���ʽ������,��0��ʾ�ɹ�
	*/
	
	// ����ʹ�òο�time��׼��
	struct tm *struct_t;
	struct_t->tm_year = year-1900;
	struct_t->tm_mon = month-1;
	struct_t->tm_mday = day;
	
	// ��ʽ��ʱ��
	return strftime(timeArray , 10, "%Y/%m/%d", struct_t);
}

pbook _createNode(){
	// ����:�����½ڵ�,����ʼ��
	
	int year, month, day;
	pbook newBook;
	
	// ��̬��������
	newBook = (pbook)malloc(sizeof(book));
	printf("%d\n", newBook==NULL );
	printf("%d\n", sizeof(book) );
	
	// �������ʧ��
	if (newBook==NULL){
		return NULL;
	}
	
	// ¼��ṹ�����ݲ�Ч�����ݺϷ���
	do{	
		printf("������ͼ�����(����Ϊ��!!!):");
		scanf("%s", newBook->title);
	}while(!strlen(newBook->title));

	printf("%d\n", sizeof(book) );
	do{
		printf("��������������(����Ϊ��!!!):");
		scanf("%s", newBook->author);
	}while(!strlen(newBook->author));
	
	do{
		printf("�������鼮�������(1900���Ժ�):");
		scanf("%d", &year);
	}while(year < 1900);
	
	do{
		printf("�������鼮�����·�(1-12):");
		scanf("%d", &month);
	}while(month < 1 || month > 12);
	
	do{
		printf("�������鼮��������:(1-31)");
		scanf("%d", &day);
	}while(day < 1 || day > 31);
	
	// ��ʱ���ʽ����洢���ṹ���time��Ա��
	formatTime(newBook->time, year, month, day);
	
	do{
		printf("�������鼮�۸�(���ܹ�Ϊ������0!!!):");
		scanf("%lf", &newBook->price);
	}while(newBook->price <= 0);

	return newBook;
}

int addBook(ppbook phead){
	pbook newBook = _createNode();
	
	// �½�ʧ��
	if (newBook == NULL){
		return 0;
	}
	
	// ���ͷָ��ֵΪ��
	if (*phead==NULL){
		*phead = newBook;
		newBook->next = NULL;
		return 1;
	}
	
	// �������head -> newNode -> headԭ��ָ�����һ�ڵ�
	newBook->next = (*phead)->next;
	(*phead)->next = newBook;
	return 1;
}

int removeBook(ppbook phead, char *title){
	// ����:ɾ��ָ������
	// ��־λ,���ڱ���Ƿ��ҵ���Ӧ��������
	int find = 0;
	// ����ǰһ���ڵ�͵�ǰ�ڵ�
	pbook curNode, preNode = NULL;
	
	for (curNode=*phead; curNode!=NULL; preNode=curNode, curNode=curNode->next){
		// ����,�Ƚ�����
		if (strcmp(curNode->title, title) == 0){
			find = 1;
			break;
		}
	}
	
	if (find){
		// ���ɾ������ͷ�ڵ�
		if (preNode == NULL){
			*phead = (*phead)->next;
			free(curNode);
		}
		else{
		// ɾ���Ĳ���ͷ�ڵ�
			preNode->next = curNode->next;
			free(curNode);
		}
	}
	
	return find;
}

// �ͷ���������ڵ�
int clearAllNodes(pbook head){
	pbook nextNode, curNode;
	for (curNode=head; curNode!=NULL; curNode=nextNode){
		nextNode=curNode->next;
		free(curNode);
	}
	return 1;
}