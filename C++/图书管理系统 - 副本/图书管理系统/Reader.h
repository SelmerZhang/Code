#ifndef _READER_H
#define _READER_H
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
#include"print.h"

using namespace std;
class Reader:public virtual print,public Book
{
public:
	Reader();
	~Reader();
	string getReaderCode(string code);
	void getName();
	void getBook(Book book);
	void returnBook(Book book);
	string putName();
	string putCode();
	void getCount();
	void AddCount();
	void ReduceCount();
	friend istream& operator>>(istream &is, Reader &reader);
	friend ostream& operator<<(ostream &os, Reader &reader);
	void display();
	vector<Book> readerbook;

protected:
	string m_strName;
	string m_strCode;	
	int UserBookCount;//�����û���ͼ�鱾��
};

class Teacher_Reader:virtual public Reader
{
public:
	Teacher_Reader();
	~Teacher_Reader();
	void display();
	friend istream& operator>>(istream &is, Reader &reader);
	friend ostream& operator<<(ostream &os, Reader &reader);
private:
	string m_strProfession;
};


Teacher_Reader::Teacher_Reader()
{
}
istream& operator>>(istream &is, Reader &Teacher_Reader)
{

}
ostream& operator<<(ostream &os, Reader &Teacher_Reader)
{

}
void Teacher_Reader::display()
{
	
	cout << "����һλ��ʦ���ߣ���ʦ��רҵ�ǣ�" << m_strBookName<<endl;
	Reader::display();
}

Teacher_Reader::~Teacher_Reader()
{
}

class Student_reader :virtual public Reader
{
public:
	Student_reader();
	~Student_reader();
	void display();
	friend istream& operator>>(istream &is, Reader &reader);
	friend ostream& operator<<(ostream &os, Reader &reader);
private:
	string m_strAcademy;
	string m_strMajor;
	string m_strGrade;

}; 
Student_reader::Student_reader()
{
}

void Student_reader::display()
{
	
	cout << "����һλѧ�����ߣ�ѧ����ѧԺ�ǣ�" << m_strAcademy << endl;
	cout << "ѧ����רҵ��:" << m_strMajor << endl;
	cout << "ѧ�����꼶�ǣ�" << m_strGrade << endl;
	Reader::display();
}
Student_reader::~Student_reader()
{
}


class Outside_campus_Reader :virtual public Reader
{
public:
	Outside_campus_Reader();
	~Outside_campus_Reader();
	void display();
	friend istream& operator>>(istream &is, Reader &reader);
	friend ostream& operator<<(ostream &os, Reader &reader);
private:
	string m_strAdress;
	string m_strTelephoneNumber;
};

void Outside_campus_Reader::display()
{
	cout << "����һλУ����ߣ����ߵ�סַ�ǣ�" << m_strAdress << endl;
	cout << "���ߵĵ绰�����ǣ�" << m_strTelephoneNumber << endl;
	Reader::display();
}
Outside_campus_Reader::Outside_campus_Reader()
{
}

Outside_campus_Reader::~Outside_campus_Reader()
{
}







#endif