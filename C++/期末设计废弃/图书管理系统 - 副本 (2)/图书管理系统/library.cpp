#include "library.h"
library::library()
{
}

library::~library()
{
}

bool library::usertype()
{
		string code;
		while (true)
		{
			cout << "��������λ������Ա�˺ţ������û���λ���˺ţ�" << endl;
			cin >> code;
			m_strRCode = code;
			if (m_strRCode.size() == 2)//����Ա��λ���˺�
			{
				return true;
				break;
			}

			if (m_strRCode.size() == 4)//�û���λ���˺�
			{
				return false;
				break;
			}

			else//�˺����벻��ȷ
			{
				cout << "����ȷ�����˺�" << endl;
				continue;
			}
		}
}

int library::managelogin()
{	
		system("cls");//����
		cout << "��������ѡ������Ҫ�����Ĳ�������������Ӧ��š�����" << endl;
		cout << "��������������������1���鿴ͼ�顤������������������" << endl;
		cout << "��������������������2������ͼ�顤������������������" << endl;
		cout << "��������������������3��ɾ��ͼ�顤������������������" << endl;
		cout << "��������������������4������ͼ�顤������������������" << endl;
		cout << "��������������������5��������Ϣ��������������������" << endl;
		int chiose;
		while (true)
		{
			cin >> chiose;
			if (chiose == 1 || chiose == 2 || chiose == 3 || chiose == 4 || chiose == 5)
			{
				return chiose;
				break;
			}
			else
			{
				cout << "�������ѡ����ȷ������������" << endl;
				cout << "�Ƿ����ѡ�����밴��1�����밴��0" << endl;
				int a;
				cin >> a;
				if (a == 1)
				{
					continue;
				}
				else
				{
					cout << "��ѡ�����˳�" << endl;
					return 0;
					break;
				}
			}
		}	
}

void library::BookInventory()
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
				for (unsigned i = 0; i <read.info.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
				{
					read.info[i].displayBook();
				}
				break;
			}
			if (key == "2")//�Զ���ģ����ѯ
			{
				cout << "��������������������Ҫ��ѯ��ͼ�����ƻ��š�����������" << endl;
				string key1;
				cin >> key1;
				int a = 0;
				for (unsigned i = 0; i < read.info.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
				{
					if ((read.info[i].m_strBookName.find(key1) != string::npos) || (read.info[i].m_iBookCode.find(key1) != string::npos))
					{
						cout << "�� ��" << key1 << "�� ��ص�ͼ����Ϣ:";
						read.info[i].displayBook();
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

void library::changeBook()
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
		for (unsigned i = 0; i < read.info.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
		{
			if ((read.info[i].m_strBookName.find(key) != string::npos) || (read.info[i].m_iBookCode.find(key) != string::npos))
			{
				a++;//��¼��ѯ���ı���
				cout << "�� ��" << key << "�� ��صĵ� " << a << " ��ͼ����Ϣ:" << endl;
				read.info[i].displayBook();
				cout << endl;
				p = &(read.info[i]);
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
		for (unsigned i = 0; i < read.info.size(); i++)
		{
			if (&(p[t - a]) == &(read.info[i]))//��ַ��ͬʱ	
			{
				cout << "�ҵ���ַ��ͬ��info" << endl;
				read.info[i] = *p;
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

void library::DropBook()
{
	//1������ͼ����Ϣ�����ϱ�Ŵ�ӡ
	//2��ѡ��Ҫɾ����ͼ����
	//3��ɾ��ͼ��,ע��βָ��ı仯
	//4�������ļ�
	Read_Write<Book> drop;
	drop.ToRead("book.txt");
	int top = 0;
	for (unsigned i = 0; i < drop.info.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
	{
		top++;
		cout << "�� " << top << " ��ͼ��" << endl;
		drop.info[i].displayBook();
	}
	int key1;
	while (true)
	{
		cout << "��ѡ����Ҫɾ����ͼ�����" << endl;
		cin >> key1;
		if (key1 >= 0 && key1 <= top)
		{
			if ((drop.info.begin() + (key1 - 1)) != drop.info.end())
			{
				drop.info.erase(drop.info.begin() + (key1 - 1));//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
			}
			else
			{
				drop.info.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
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

void library::AddBook()
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
		R_W.info.push_back(b);
		cout << "�Ƿ����¼��ͼ�飬�ǣ��밴y(Y)���񣺰�������˳�" << endl;
		cin >> key;
		if (key != "y" && key != "Y")//�ж��Ƿ��������
			break;
	}
	R_W.ToWrite("book.txt");//�����ļ�
}


int library::ReaderType()
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
		}
		else
		{
			cout << "���벻��ȷ" << endl;
			cout << "���������밴1������������˳�" << endl;
			string key2;
			cin >> key2;
			if (key2 == "1")
			{
				cout << "���������룺" << endl;
				continue;
			}
			else
			{
				break;
				key1 = 0;
			}
		}
		
	}
	
	return key1;
}

int library::Readerchiose()
{
	system("cls");//����
	cout << "�û���" << m_strRCode << endl;
	cout << "��������ѡ������Ҫ�����Ĳ�������������Ӧ��š�����" << endl;
	cout << "��������������������1������ͼ�顤������������������" << endl;
	cout << "��������������������2�����顤������������������" << endl;
	cout << "��������������������3�����顤������������������" << endl;
	int chiose;
	while (true)
	{
		cin >> chiose;
		if (chiose == 1 || chiose == 2 || chiose == 3)
		{
			return chiose;
			break;
		}
		else
		{
			cout << "�������ѡ����ȷ������������" << endl;
			cout << "�Ƿ����ѡ�����밴��1�����밴��0" << endl;
			int a;
			cin >> a;
			if (a == 1)
			{
				continue;
			}
			else
			{
				cout << "��ѡ�����˳�" << endl;
				return 0;
				break;
			}
		}
	}
}

void library::checktype()
{
	cout << "��ѡ��鿴�Ķ������ͣ�" << endl;
	cout << "1����ְ�������û�" << endl;
	cout << "2��ѧ�������û�" << endl;
	cout << "3��У������û�" << endl;
	int key1;
	cin >> key1;
	switch (key1)
	{
	case 1:
	{
		Read_Write<Teacher_Reader>ReaderUser;
		ReaderUser.ToRead("Teacher_Reader.txt");
		for (unsigned i = 0; i < ReaderUser.info.size(); i++)
		{
			ReaderUser.info[i].display();
		}
		break;
	}
	case 2:
	{
		Read_Write<Student_Reader>ReaderUser;
		ReaderUser.ToRead("Student_Reader.txt");
		for (unsigned i = 0; i < ReaderUser.info.size(); i++)
		{
			ReaderUser.info[i].display();
		}
		break;
	}
	case 3:
	{
		Read_Write<Outside_campus_Reader>ReaderUser;
		ReaderUser.ToRead("Outside_campus_Reader.txt");
		for (unsigned i = 0; i < ReaderUser.info.size(); i++)
		{
			ReaderUser.info[i].display();
		}
		break;
	}
	default:
		break;
	}
}
