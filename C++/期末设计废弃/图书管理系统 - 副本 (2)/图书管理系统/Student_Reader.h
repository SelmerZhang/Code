#ifndef STUDENT_READER_H
#define STUDENT_READER_H
#include"Reader.h"
class Student_Reader :virtual public Reader
{
public:
	Student_Reader();
	~Student_Reader();
	void display();
	friend istream& operator>>(istream &is, Student_Reader &student_reader);
	friend ostream& operator<<(ostream &os, Student_Reader &student_reader);
private:
	string m_strAcademy;
	string m_strMajor;
	string m_strGrade;

};

#endif
