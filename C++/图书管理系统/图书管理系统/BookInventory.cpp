#include"BookInventory.h"
//�յĹ�����
BookInventory::BookInventory()
{
	
}

//void BookInventory::readBook()
//{
//	Book b;
//	ifstream file("book.txt", ios::in);
//	while (!file.eof())//��ȡtxt����
//	{
//		if (!file)
//		{
//			cout << "BookInventory:�ļ�δ������" << endl;
//			break;
//		}
//		file >> b;
//		book.push_back(b);
//	}
//	book.pop_back();
//	file.close();
//}
void BookInventory::printBook()
{
	//1�������ѯ����
	//2����������ȡ����ӡ
	Read_Write <Book> read;//���ļ����ݶ���book������ȥ
	read.ToRead("book.txt");//��ȡtxt�е�����
	cout << "������������������ѯ����ͼ���밴1����������������" << endl;
	cout << "��������������������ȷ��ѯ�밴2������������������" << endl;
	cout << "��������������������������˳�������������������" << endl;
	string key;
	cin >> key;
	while (true)
	{
		if (key == "1")
		{ 
			for (unsigned i = 0; i <read.book.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
			{
			read.book[i].displayBook();
			}
			break;
		}
		if (key == "2")//�Զ���ģ����ѯ
		{
			cout << "��������������������Ҫ��ѯ��ͼ�����ƻ��š�����������" << endl;
			string key1;
			cin >> key1;
			int a=0;
			for (unsigned i = 0; i < read.book.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
			{
				if ((read.book[i].m_strBookName.find(key1) != string::npos) || (read.book[i].m_iBookCode.find(key1) != string::npos))
				{
					cout << "�� ��" << key1 << "�� ��ص�ͼ����Ϣ:";
					read.book[i].displayBook();
					cout << endl;
					a++;//��¼��ѯ���ı���
				}
			}
			if (a == 0)
			{
				cout << "û����Ҫ�ҵ�ͼ�飬��淶������롣���������밴1���˳��밴�����" << endl;
				string key2;
				cin >> key2;
				if (key2 == "1")
					continue;
				else
				{
					cout << "���˳��˲�ѯ" << endl;
					break;
				}
			}
			break;
		}
	}
}

BookInventory::~BookInventory()
{

}