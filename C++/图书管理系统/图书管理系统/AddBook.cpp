#include"AddBook.h"

//int AddBook::m_iSum = 0;//��ʼ��sum

AddBook::AddBook()
{
	m_iSum = 0;
}

void AddBook::getBook()
{
	//1������ͼ����Ϣ
	//2����ͼ����Ϣд���ļ�
	string name;
	string code;
	int count;
	string key;
	Read_Write<Book> R_W;
	while (1)
	{
		cout << "������ͼ������" << endl;
		cin >> name;
		cout << "������ͼ����" << endl;
		cin >> code;
		cout << "���������ͼ�����Ŀ" << endl;
		cin >> count;
		Book b(name, code, count);
		m_iSum++;
		R_W.book.push_back(b);
		cout << "�Ƿ����¼��ͼ�飬�ǣ��밴y(Y)���񣺰�������˳�" << endl;
		cin >> key;
		if (key != "y" && key != "Y")//�ж��Ƿ��������
			break;
	}
	R_W.ToWrite("book.txt");//�����ļ�
	/*ofstream file("book.txt", ios::app | ios::out);
	if (!file)
	{
		cout << "�ļ���ʧ��" << endl;
	}
	for (unsigned i = 0; i < book.size(); i++)
	{
		file << book[i];
	}
	file.close();*/
}

AddBook::~AddBook()
{
}