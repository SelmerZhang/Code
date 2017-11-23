#ifndef _BOOK_H
#define _BOOK_H

#include<string>
#include"print.h"
using namespace std;

class Book:virtual public print
{
public:
	Book();
	Book(string book_name, string book_code, int book_count);
	virtual ~Book();
	friend istream& operator>>(istream &is, Book &book);
	friend ostream& operator<<(ostream &os, Book &book);
	void displayBook();
//protected:
	string m_strBookName;
	string m_iBookCode;//ͼ����
	int m_iBookCount;//ʣ�౾��
};

#endif