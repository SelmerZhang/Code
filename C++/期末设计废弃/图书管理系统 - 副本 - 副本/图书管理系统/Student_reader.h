#ifndef STUDENT_READER_H
#define STUDENT_READER_H
#include"Reader.h"
class Student_reader :virtual public Reader
{
public:
	Student_reader();
	~Student_reader();
	void display();
	friend istream& operator>>(istream &is, Student_reader &student_reader);
	friend ostream& operator<<(ostream &os, Student_reader &student_reader);
private:
	string m_strAcademy;
	string m_strMajor;
	string m_strGrade;

};


istream& operator>>(istream &is, Student_reader &student_reader)
{
	is >> student_reader.m_strAcademy >> student_reader.m_strMajor >> student_reader.m_strGrade;
	istream& operator>>(istream &is, Reader &reader);
	return is;
}
ostream& operator<<(ostream &os, Student_reader &student_reader)
{
	os << student_reader.m_strAcademy << ' ' << student_reader.m_strMajor << ' ' << student_reader.m_strGrade<< ' ';
	istream& operator<<(istream &os, Reader &reader);
	return os;
}
void Student_reader::display()
{

	cout << "����һλѧ�����ߣ�ѧ����ѧԺ�ǣ�" << m_strAcademy << endl;
	cout << "ѧ����רҵ��:" << m_strMajor << endl;
	cout << "ѧ�����꼶�ǣ�" << m_strGrade << endl;
	Reader::display();
}

#endif
