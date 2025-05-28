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
	
	// 将数据读从文件读取到链表内
//	if (readNodes(&head) == 0){
//		printf("还没有数据文件,或者读取数据出错\n");
//	}
	
	// 循环接收用户输入
	do {
		// 显示菜单
		showMenu();
		
		// 接收用户输入
		if (recChoice(&choice) == 0){
			printf("请输入有效的选项\n");
			continue;
		}

		switch (choice){
			case 0:
				break;
				
			case 1:
				if (showAllBooks(head) == 0){
					printf("图书列表为空,请先添加书籍\n");
					continue;
				}
				break;
				
			case 2:
				if (searchBook(head) == 0){
					printf("图书列表为空,或者编号不合法\n");
					continue;
				}
				break;
				
			case 3:
				if (addBook(&head) == 0){
					printf("新建书籍失败\n");
					continue;
				}
				break;
				
			case 4:
				if (removeBook(&head, title) == 0){
					printf("删除失败\n");
					continue;
				}
				break;
				
			case 5:
				if (clearAllNodes(head) != 1){
					printf("清除所有节点出错\n");
					continue;
				}
				break;
				
			case 6:
				if (saveNodes(head) == 0){
					printf("保存数据出错\n");
					continue;
				}
				break;
		}
	}while(choice);
	
	clearAllNodes(head);
	
	system("pause");
	return 0;
}