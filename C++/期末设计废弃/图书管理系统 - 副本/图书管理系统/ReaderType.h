#ifndef READERTYPE_H
#define READERTYPE_H
#include"Outside_campus_Reader.h"
#include"Student_reader.h"
#include"Teacher_Reader.h"
#include"BorrowBook.h"
#include"BookInventory.h"

using namespace std;

class ReaderType
{
public:
	ReaderType();
	~ReaderType();
	int Readertype();
private:
	int key;
};

int ReaderType::Readertype()
{
	cout << "��ѡ��������ͣ�" << endl;
	cout << "1����ְ�������û�" << endl;
	cout << "2��ѧ�������û�" << endl;
	cout << "3��У������û�" << endl;
	int key1;
	while (1)//ѡ������û�����
	{
		cin >> key1;
		if (key1 == 1 || key1 == 2 || key1 == 3)
		{
			break;
			key = key1;
		}
		else
		{
			cout << "���벻��ȷ" << endl;
			cout << "���������밴1������������˳�" << endl;
			string key2;
			cin >> key2;
			if (key2 == "1")
			{
				continue;
			}
			else
			{
				break;
				key = 0;
			}
		}
	}
	return key;

}


#endif