/*
	���Ͷ����ļ�, ����Ҫ�õ������������ﶨ��
*/

// ����ظ�����ͷ�ļ�������,���µı���
#ifndef DATATYPEDEF
#define DATATYPEDEF

struct Book{
	char title[128];
	char author[128];
	char time[16];
	double price;
	struct Book *next;
};

// Ϊ�ṹ������_Bookȡ����book; _Book *ָ��ȡ����pbook;
// _Book **ָ���ָ��ȡ����ppbook;
typedef struct Book book, *pbook, **ppbook;

#endif