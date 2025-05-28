/*
	数据写入和读取模块,与文件交互
*/

#include <stdio.h>
#include <stdlib.h>
#include "dataTypedef.c"
#include "configuration.c"

int saveNodes(pbook head){
	// 功能:保存链表上所有节点数据到指定文件
	
	FILE *fp;
	pbook iNode;
	
	// 打开文件
	if ((fp = fopen(BASE_PATH, "wb")) == NULL) return 0;
	
	// 循环链表并写入数据
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		if (fwrite(iNode, sizeof(book), 1, fp) != 1) return 0;
	}
	// 关闭文件
	fclose(fp);
	
	return 1;
}

int readNodes(ppbook phead){
	// 功能:读取所有节点数据,组成一个链表
	
	// tailBook用于标记链表最后一个节点
	FILE *fp;
	pbook newBook, tailBook;
	
	// 打开文件
	if ((fp=fopen(BASE_PATH, "rb")) == NULL) return 0;
	
	// 读取文件所有内容
	while (!feof){
		// 动态创建节点
		if ((newBook = (pbook)malloc(sizeof(book))) == NULL) return 0;
		
		// 将节点添加到头指针(链表首个节点)
		if (*phead = NULL){
			*phead = newBook;
			newBook->next = NULL;
			tailBook = newBook;
		}
		// 将节点添加到链表尾部
		else{
			tailBook->next = newBook;
			tailBook = newBook;
			newBook->next = NULL;
		}
		
		// 将文件中读取的结构体数据存放到新开的节点中
		if (fread(newBook, sizeof(book), 1, fp) != 1) return 0;
	}
	
	return 1;
}