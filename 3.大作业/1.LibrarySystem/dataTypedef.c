/*
	类型定义文件, 程序要用到的类型在这里定义
*/

// 解决重复导入头文件的问题,是新的报错
#ifndef DATATYPEDEF
#define DATATYPEDEF

struct Book{
	char title[128];
	char author[128];
	char time[16];
	double price;
	struct Book *next;
};

// 为结构体类型_Book取别名book; _Book *指针取别名pbook;
// _Book **指针的指针取别名ppbook;
typedef struct Book book, *pbook, **ppbook;

#endif