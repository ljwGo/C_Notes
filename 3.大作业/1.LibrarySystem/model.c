/*
	����д��Ͷ�ȡģ��,���ļ�����
*/

#include <stdio.h>
#include <stdlib.h>
#include "dataTypedef.c"
#include "configuration.c"

int saveNodes(pbook head){
	// ����:�������������нڵ����ݵ�ָ���ļ�
	
	FILE *fp;
	pbook iNode;
	
	// ���ļ�
	if ((fp = fopen(BASE_PATH, "wb")) == NULL) return 0;
	
	// ѭ������д������
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		if (fwrite(iNode, sizeof(book), 1, fp) != 1) return 0;
	}
	// �ر��ļ�
	fclose(fp);
	
	return 1;
}

int readNodes(ppbook phead){
	// ����:��ȡ���нڵ�����,���һ������
	
	// tailBook���ڱ���������һ���ڵ�
	FILE *fp;
	pbook newBook, tailBook;
	
	// ���ļ�
	if ((fp=fopen(BASE_PATH, "rb")) == NULL) return 0;
	
	// ��ȡ�ļ���������
	while (!feof){
		// ��̬�����ڵ�
		if ((newBook = (pbook)malloc(sizeof(book))) == NULL) return 0;
		
		// ���ڵ���ӵ�ͷָ��(�����׸��ڵ�)
		if (*phead = NULL){
			*phead = newBook;
			newBook->next = NULL;
			tailBook = newBook;
		}
		// ���ڵ���ӵ�����β��
		else{
			tailBook->next = newBook;
			tailBook = newBook;
			newBook->next = NULL;
		}
		
		// ���ļ��ж�ȡ�Ľṹ�����ݴ�ŵ��¿��Ľڵ���
		if (fread(newBook, sizeof(book), 1, fp) != 1) return 0;
	}
	
	return 1;
}