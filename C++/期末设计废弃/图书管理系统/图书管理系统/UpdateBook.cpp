#include"UpdateBook.h"

UpdateBook::UpdateBook()
{
}

void UpdateBook::changeBook()
{
	//1����ȡͼ���ļ�
	//2��ģ����ѯ���޸�ͼ��
	//3��ѡ����޸ĵ�ͼ�鼰���ݣ��������޸�����
	//4�������ļ���Ϣ
	Read_Write<Book> read;
	read.ToRead("book.txt");
	int a = 0;
	Book *p = new Book[100];//���ڽ�����Ҫ�޸ĵ�ͼ��
	string key2;//�����ж��Ƿ���ҳ���Ҫ�޸ĵ�ͼ�飬���ж��Ƿ���������޸�
	while (true)//�ҳ���Ҫ�޸ĵ�ͼ��
	{
		system("cls");
		cout << "��������������������������µ�ͼ�����ƻ���ͼ���š���������������" << endl;
		string key;
		cin >> key;
		for (unsigned i = 0; i < read.book.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
		{
			if ((read.book[i].m_strBookName.find(key) != string::npos) || (read.book[i].m_iBookCode.find(key) != string::npos))
			{
				a++;//��¼��ѯ���ı���
				cout << "�� ��" << key << "�� ��صĵ� " << a << " ��ͼ����Ϣ:" << endl;
				read.book[i].displayBook();
				cout << endl;
				p = &(read.book[i]);
				p++;
			}
		}
		if (a == 0)//δ�淶�����ж�
		{
			cout << "û����Ҫ�޸�ͼ�飬��淶������롣���������밴1���˳��밴�����" << endl;

			cin >> key2;
			if (key2 == "1")
				continue;
			else
			{
				cout << "���˳����޸�" << endl;
				break;
			}
		}
		else
			break;//��ѯ������˳���ѯ		
	}

	while (key2 != "1")//δ�˳��޸�
	{

		int t;
		if (a == 1)
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���µ�ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		cout << "��ѡ����Ҫ�޸ĵ�����" << endl;
		cout << "1������    " << "2�����    " << "3��ͼ����Ŀ" << endl;
		int chiose;
		cin >> chiose;
		switch (chiose)
		{
		case 1:
		{
			cout << "�������µ�����" << endl;
			string name;
			cin >> name;
			p[t - a].m_strBookName = name;
			break;
		}
		case 2:
		{
			cout << "�������µı��" << endl;
			string code;
			cin >> code;
			p[t - a].m_iBookCode = code;
			break;
		}
		case 3:
		{
			cout << "�������µ�ͼ����Ŀ" << endl;
			int count;
			cin >> count;
			p[t - a].m_iBookCount = count;
			break;
		}
		default:
			cout << "����ѡ����ȷ" << endl;
			break;
		}
		//��Ҫ�ҵ���ַ�����ļ������޸�
		for (unsigned i = 0; i < read.book.size(); i++)
		{
			if (&(p[t - a]) == &(read.book[i]))//��ַ��ͬʱ	
			{
				cout << "�ҵ���ַ��ͬ��book" << endl;
				read.book[i] = *p;
			}
		}
		cout << "�����޸��밴1������������˳�" << endl;
		string key3;
		cin >> key3;
		if (key3 == "1")
		{ 
			continue;
		}
		else
		{
			cout << "�޸Ľ���" << endl;
			break;
		}
	}//while����

	//���ļ���գ�������д��
	ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
	file1.close();
	read.ToWrite("book.txt");
	
	delete[] p;
	p = NULL;//�ڴ��ͷų������⣬����������
}

void UpdateBook::DropBook()
{
	//1������ͼ����Ϣ�����ϱ�Ŵ�ӡ
	//2��ѡ��Ҫɾ����ͼ����
	//3��ɾ��ͼ��,ע��βָ��ı仯
	//4�������ļ�
	Read_Write<Book> drop;
	drop.ToRead("book.txt");
	top = 0;
	for (unsigned i = 0; i < drop.book.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
	{
		top++;
		cout << "�� " << top << " ��ͼ��" << endl;
		drop.book[i].displayBook();
	}
	int key1;	
	while (true)
	{
		cout << "��ѡ����Ҫɾ����ͼ�����" << endl;
		cin >> key1;
		if (key1 >= 0 && key1 <= top)
		{
			if ((drop.book.begin() + (key1 - 1)) != drop.book.end())
			{
				drop.book.erase(drop.book.begin() + (key1 - 1));//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
			}
			else
			{
				drop.book.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
			}

			cout << "�Ƿ�Ҫ����ɾ��" << endl << "���밴1������������˳�" << endl;
			string key2;
			if (key2 == "1")//�ж��Ƿ����ɾ��
			{
				continue;
			}
			else
			{
				cout << "ɾ����ϣ����˳�" << endl;
				break;
			}
		}
		else
		{
			cout << "����ȷ����" << endl << "���������밴1������������˳�";
			string key3;
			if (key3 == "1")
			{ 
				continue;
			}
			else
			{
				cout << "���˳���ɾ��ͼ�����" << endl;
				break;
			}
		}
	}
	//���ļ���գ�������д��ɾ���������
	ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
	file1.close();
	drop.ToWrite("book.txt");
}

UpdateBook::~UpdateBook()
{
}