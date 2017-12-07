#ifndef _READER_H
#define _READER_H
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"

using namespace std;
class Reader:public Book
{
public:
	Reader();
	~Reader();
	int getReaderCode(int code);
	void getName();
	void getBook(Book book);
	void returnBook(Book book);
	string putName();
	int putCode();
	void getCount();
	void AddCount();
	virtual void display();
	void ReduceCount();
	vector<Book> readerbook;	
protected:
	string m_strName;
	int m_strCode;	
	int UserBookCount;//�����û���ͼ�鱾��
};



#endif