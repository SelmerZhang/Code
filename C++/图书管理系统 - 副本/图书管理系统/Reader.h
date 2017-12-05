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
	int UserBookCount;//计算用户的图书本数
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
	
	cout << "这是一位老师读者，老师的专业是：" << m_strBookName<<endl;
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
	
	cout << "这是一位学生读者，学生的学院是：" << m_strAcademy << endl;
	cout << "学生的专业是:" << m_strMajor << endl;
	cout << "学生的年级是：" << m_strGrade << endl;
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
	cout << "这是一位校外读者，读者的住址是：" << m_strAdress << endl;
	cout << "读者的电话号码是：" << m_strTelephoneNumber << endl;
	Reader::display();
}
Outside_campus_Reader::Outside_campus_Reader()
{
}

Outside_campus_Reader::~Outside_campus_Reader()
{
}







#endif