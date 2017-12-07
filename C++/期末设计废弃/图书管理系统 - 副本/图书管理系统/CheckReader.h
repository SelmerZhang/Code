#ifndef CHECKREADER_H
#define CHECKREADER_H
#include"Outside_campus_Reader.h"
#include"Student_reader.h"
#include"Teacher_Reader.h"
#include"Read_Write.h"

using namespace std;

class CheckReader
{
public:
	CheckReader();
	~CheckReader();
	void checktype();
private:

};


void CheckReader::checktype()
{
	cout << "��ѡ��Ҫ�鿴�Ķ������ͣ�" << endl;
	cout << "1����ְ�������û�" << endl;
	cout << "2��ѧ�������û�" << endl;
	cout << "3��У������û�" << endl;
	int key;
	cin >> key;
	switch (key)
	{
	case 1:
	{
		Read_Write<Teacher_Reader>ReaderUser;
		ReaderUser.ToRead("Teacher_Reader.txt");
		for (unsigned i = 0; i < ReaderUser.book.size(); i++)
		{
			ReaderUser.book[i].display();
		}
		break;
	}
	case 2:
	{
		Read_Write<Student_reader>ReaderUser;
		ReaderUser.ToRead("Student_reader.txt");
		for (unsigned i = 0; i < ReaderUser.book.size(); i++)
		{
			ReaderUser.book[i].display();
		}
		break;
	}
	case  3:
	{
		Read_Write<Outside_campus_Reader>ReaderUser;
		ReaderUser.ToRead("Outside_campus_Reader.txt");
		for (unsigned i = 0; i < ReaderUser.book.size(); i++)
		{
			ReaderUser.book[i].display();
		}
		break;
	}
	default:
	{
		cout << "����ȷѡ���޴������û�����ѯʧ��" << endl;
		break;
	}
		
	}
}
CheckReader::CheckReader()
{
}

CheckReader::~CheckReader()
{
}

#endif