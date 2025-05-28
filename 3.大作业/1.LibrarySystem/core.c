/*
	核心的程序逻辑
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dataTypedef.c"


void showMenu(){
	// 功能:列出功能菜单
	printf("+--------------------------------------+\n");
	printf("|\t\t图书管理系统\t\t|\n");
	printf("+--------------------------------------+\n");
	printf("1 列出所有图书\n");
	printf("2 查询指定图书\n");
	printf("3 新增记录\n");
	printf("4 删除记录\n");
	printf("5 清空图书列表\n");
	printf("6 保存修改\n");
	printf("0 退出\n");
	printf("请输入选择的功能:\n");
	putchar('\n');
}

int recChoice(int *pChoice){
	// 功能:接收用户输入的选项
	// 参数:pChoice,存储选项值变量的地址
	// 返回值:如果不合法,返回0; 合法返回1
	int x;
	scanf("%d", &x);
	
	// 对选项合法性进行效验
	if (x<0 || x>6){
		// 不合法
		return 0;
	}
	*pChoice = x;
	return 1;
}

int showAllBooks(pbook head){
	// 功能:显示所有书籍
	// 参数:head 链表头指针
	// 返回值:0表示头指针为空,无法遍历; 1表示可以遍历
	if (head == NULL)
		return 0;
	
	int i;
	pbook iNode;
	
	printf("---------------所有书籍---------------\n");
	for (i=1, iNode=head; iNode!=NULL; iNode=iNode->next){
		printf("编号:%d 书名%s\n", i++, iNode->title);
	}
	putchar('\n');
}

int searchBook(pbook head){
	// 功能:搜索某个编号的书籍的详细信息
	// 参数:head 链表头指针
	// 返回值:0表示头指针为空或编号不合法,无法遍历; 1表示找到; -1表示找不到
	int ordinal, i;
	pbook iNode;
	
	// 输入编号
	printf("请输入编号:");
	scanf("%d", &ordinal);
	
	if (head == NULL || ordinal < 1)
		return 0;
	
	// 遍历链表,找到对应的编号书籍
	for (i=1, iNode=head; iNode!=NULL; iNode=iNode->next, i++){
		if (i == ordinal){
			printf("-------------找到这本书了!!!-------------\n");
			printf("书名: %s\n", iNode->title);
			printf("作者: %s\n", iNode->author);
			printf("时间: %s\n", iNode->time);
			printf("价格: %f.2\n", iNode->price);
			putchar('\n');
			return 1;
		}
	}
	putchar('\n');
	return 0;
}

int formatTime(char *timeArray, int year, int month, int day){
	/*  
	功能:将年月日格式化,存储子在book结构体的time成员中
	参数:timeArray存放格式化时间的数组地址
	返回值:0表示时间格式化出错,非0表示成功
	*/
	
	// 具体使用参考time标准库
	struct tm *struct_t;
	struct_t->tm_year = year-1900;
	struct_t->tm_mon = month-1;
	struct_t->tm_mday = day;
	
	// 格式化时间
	return strftime(timeArray , 10, "%Y/%m/%d", struct_t);
}

pbook _createNode(){
	// 功能:创建新节点,并初始化
	
	int year, month, day;
	pbook newBook;
	
	// 动态开辟新书
	newBook = (pbook)malloc(sizeof(book));
	printf("%d\n", newBook==NULL );
	printf("%d\n", sizeof(book) );
	
	// 如果开辟失败
	if (newBook==NULL){
		return NULL;
	}
	
	// 录入结构体数据并效验数据合法性
	do{	
		printf("请输入图书标题(不能为空!!!):");
		scanf("%s", newBook->title);
	}while(!strlen(newBook->title));

	printf("%d\n", sizeof(book) );
	do{
		printf("请输入作者姓名(不能为空!!!):");
		scanf("%s", newBook->author);
	}while(!strlen(newBook->author));
	
	do{
		printf("请输入书籍购买年份(1900年以后):");
		scanf("%d", &year);
	}while(year < 1900);
	
	do{
		printf("请输入书籍购买月份(1-12):");
		scanf("%d", &month);
	}while(month < 1 || month > 12);
	
	do{
		printf("请输入书籍购买日期:(1-31)");
		scanf("%d", &day);
	}while(day < 1 || day > 31);
	
	// 将时间格式化后存储到结构体的time成员中
	formatTime(newBook->time, year, month, day);
	
	do{
		printf("请输入书籍价格(不能够为负数或0!!!):");
		scanf("%lf", &newBook->price);
	}while(newBook->price <= 0);

	return newBook;
}

int addBook(ppbook phead){
	pbook newBook = _createNode();
	
	// 新建失败
	if (newBook == NULL){
		return 0;
	}
	
	// 如果头指针值为空
	if (*phead==NULL){
		*phead = newBook;
		newBook->next = NULL;
		return 1;
	}
	
	// 否则插入head -> newNode -> head原本指向的下一节点
	newBook->next = (*phead)->next;
	(*phead)->next = newBook;
	return 1;
}

int removeBook(ppbook phead, char *title){
	// 功能:删除指定数据
	// 标志位,用于标记是否找到对应书名的书
	int find = 0;
	// 定义前一个节点和当前节点
	pbook curNode, preNode = NULL;
	
	for (curNode=*phead; curNode!=NULL; preNode=curNode, curNode=curNode->next){
		// 遍历,比较名称
		if (strcmp(curNode->title, title) == 0){
			find = 1;
			break;
		}
	}
	
	if (find){
		// 如果删除的是头节点
		if (preNode == NULL){
			*phead = (*phead)->next;
			free(curNode);
		}
		else{
		// 删除的不是头节点
			preNode->next = curNode->next;
			free(curNode);
		}
	}
	
	return find;
}

// 释放所有链表节点
int clearAllNodes(pbook head){
	pbook nextNode, curNode;
	for (curNode=head; curNode!=NULL; curNode=nextNode){
		nextNode=curNode->next;
		free(curNode);
	}
	return 1;
}