#include"Outside_campus_Reader.h"
#include"Student_reader.h"
#include"Teacher_Reader.h"
#include"BorrowBook.h"

class ReaderType
{
public:
	ReaderType();
	~ReaderType();
	void Readertype();
	void readerchiose(int ReaderChiose);
	static int key;
};

int ReaderType::key = 1;

void ReaderType::Readertype()
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

}

void ReaderType::readerchiose(int ReaderChiose)
{
	switch (key)//ѡ���û�
	{
	case 1:
	{
		BorrowBook<Teacher_Reader>  Borrow("Teacher_Reader.txt");
		while (true)
		{
			switch (ReaderChiose)
			{

			case 1://��ѯͼ��
			{
				BookInventory B;
				B.printBook();//��ѯ
				break;
			}
			case 2://����
			{
				Borrow.borrow();
				break;
			}
			case 3://����
			{
				Borrow.returnBook();
				break;
			}
			default:
				break;
			}
			string key;
			cout << "�Ƿ�������������밴1�����밴������˳�" << endl;
			cin >> key;
			if (key == "1")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		break;
	}
	case 2:
	{
		static BorrowBook<Student_reader>  Borrow("Student_reader.txt");
		while (true)
		{
			switch (ReaderChiose)
			{

			case 1://��ѯͼ��
			{
				BookInventory B;
				B.printBook();//��ѯ
				break;
			}
			case 2://����
			{
				Borrow.borrow();
				break;
			}
			case 3://����
			{
				Borrow.returnBook();
				break;
			}
			default:
				break;
			}
			string key;
			cout << "�Ƿ�������������밴1�����밴������˳�" << endl;
			cin >> key;
			if (key == "1")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		break;
	}
	case 3:
	{
		static BorrowBook<Outside_campus_Reader>  Borrow("Outside_campus_Reader.txt");
		while (true)
		{
			switch (ReaderChiose)
			{

			case 1://��ѯͼ��
			{
				BookInventory B;
				B.printBook();//��ѯ
				break;
			}
			case 2://����
			{
				Borrow.borrow();
				break;
			}
			case 3://����
			{
				Borrow.returnBook();
				break;
			}
			default:
				break;
			}
			string key;
			cout << "�Ƿ�������������밴1�����밴������˳�" << endl;
			cin >> key;
			if (key == "1")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		break;
	}
	default:
		break;
	}

}

ReaderType::ReaderType()
{
}

ReaderType::~ReaderType()
{
}