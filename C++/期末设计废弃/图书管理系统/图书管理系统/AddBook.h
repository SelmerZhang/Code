#ifndef _ADDBOOK_H
#define _ADDBOOK_H
//���ͼ��
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include"Read_Write.h"

using namespace std;

class AddBook :public Book
{
public:
	AddBook();
	virtual ~AddBook();
	void getBook();
private:
	int m_iSum;//��¼ͼ��������Ŀ
};

#endif