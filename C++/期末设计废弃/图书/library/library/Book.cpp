#include<iostream>
#include"Book.h"
using namespace std;
//ͼ����Ϣ
Book::Book()
{
	m_strBookName = "C++";
	m_iBookCode = "001";
	m_iBookCount = 2;
}

Book::Book(string book_name, string book_code, int book_count)
{
	m_strBookName = book_name;
	m_iBookCode = book_code;
	m_iBookCount = book_count;
}

Book::~Book()
{
}

istream& operator>>(istream &is, Book &book)//read
{
	is >> book.m_strBookName >> book.m_iBookCount >> book.m_iBookCode;
	return is;
}

ostream& operator<<(ostream &os, Book &book)//write
{
	os << book.m_strBookName << ' ' << book.m_iBookCount << ' ' << book.m_iBookCode << endl;
	return os;
}

void Book::displayBook()
{
	cout << "ͼ�����ƣ�" << m_strBookName << endl;
	cout << "ͼ���ţ�" << m_iBookCode << endl;
	cout << "����ʣ�ࣺ" << m_iBookCount << " ��" << endl;
	cout << endl;
}