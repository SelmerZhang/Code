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
	static int m_iBookSum;//��¼����ͼ��������Ŀ
};

#endif