#include"library.h"

library::library()
{
}

library::~library()
{
}

int library::m_strRCode = 10;
bool library::usertype()
{
	int code;
	while (true)
	{
		cout << "��������λ������Ա�˺ţ������û���λ���˺ţ�" << endl;
		cin >> code;
		m_strRCode = code;
		if (m_strRCode>9&&m_strRCode<100)//����Ա��λ���˺�
		{
			return true;
			break;
		}

		if (m_strRCode>99&&m_strRCode<10000)//�û���λ���˺�
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

void library::borrow(Read_Write<Teacher_Reader> userR_W, Read_Write<Teacher_Reader> user, Teacher_Reader reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	ifstream file(filename);
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		user.ToRead(filename);
		for (unsigned i = 0; i < user.info.size(); i++)
		{
			if (user.info[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				userR_W.info.push_back(user.info[i]);//�����û���Ϣ��ȡ����
				if ((user.info.begin() + i) != user.info.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					user.info.erase(user.info.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					user.info.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				user.ToWrite(filename);//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}
	Read_Write<Book> read;//read��info����			
	int a = 0;
	Book *p = new Book[read.info.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	Book *t = p;//t�����ڶ�p ������
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		read.ToRead("book.txt");//ÿ��ѭ�����¶�ȡinfo��Ϣ
		system("cls");
		p = t;//��һ�ֽ���������P��
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
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
			cout << "û����Ҫ��ͼ�飬��淶������롣���������밴1���˳��밴�����" << endl;

			cin >> key2;
			if (key2 == "1")
				continue;
			else
			{
				cout << "���˳��˽���" << endl;
				break;
			}
		}
		else
			break;//��ѯ������˳���ѯ		
	}

	while (key2 != "1")//δ�˳�����
	{
		int t;
		if (a == 1)
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		for (unsigned i = 0; i < read.info.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read.info[i]))//���ҵ���ͬ��ַ
			{
				if (read.info[i].m_iBookCount < 0 || read.info[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read.info[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read.info[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//userR_W.info.֮ǰ�Ѿ�user.info[i]��ʵ������,��userR_W.infoֻ��һ��Ԫ��
						userR_W.info[0].readerbook.insert(userR_W.info[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						userR_W.info.push_back(reader);
					}
					userR_W.ToWrite(filename);//׷�ӵ�Reader.txt �ļ���
					break;
				}
			}
		}
		cout << "�������" << endl;
		break;

	}//���while����

	//������ɽ��ļ���գ�������д��
	ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
	file1.close();
	read.ToWrite("book.txt");
}

void library::borrow(Read_Write<Student_Reader> userR_W, Read_Write<Student_Reader> user, Student_Reader reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	ifstream file(filename);
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		user.ToRead(filename);
		for (unsigned i = 0; i < user.info.size(); i++)
		{
			if (user.info[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				userR_W.info.push_back(user.info[i]);//�����û���Ϣ��ȡ����
				if ((user.info.begin() + i) != user.info.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					user.info.erase(user.info.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					user.info.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				user.ToWrite(filename);//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}
	Read_Write<Book> read;//read��info����			
	int a = 0;
	Book *p = new Book[read.info.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	Book *t = p;//t�����ڶ�p ������
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		read.ToRead("book.txt");//ÿ��ѭ�����¶�ȡinfo��Ϣ
		system("cls");
		p = t;//��һ�ֽ���������P��
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
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
			cout << "û����Ҫ��ͼ�飬��淶������롣���������밴1���˳��밴�����" << endl;

			cin >> key2;
			if (key2 == "1")
				continue;
			else
			{
				cout << "���˳��˽���" << endl;
				break;
			}
		}
		else
			break;//��ѯ������˳���ѯ		
	}

	while (key2 != "1")//δ�˳�����
	{
		int t;
		if (a == 1)
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		for (unsigned i = 0; i < read.info.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read.info[i]))//���ҵ���ͬ��ַ
			{
				if (read.info[i].m_iBookCount < 0 || read.info[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read.info[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read.info[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//userR_W.info.֮ǰ�Ѿ�user.info[i]��ʵ������,��userR_W.infoֻ��һ��Ԫ��
						userR_W.info[0].readerbook.insert(userR_W.info[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						userR_W.info.push_back(reader);
					}
					userR_W.ToWrite(filename);//׷�ӵ�Reader.txt �ļ���
					break;
				}
			}
		}
		cout << "�������" << endl;
		break;

	}//���while����

	//������ɽ��ļ���գ�������д��
	ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
	file1.close();
	read.ToWrite("book.txt");
}

void library::borrow(Read_Write<Outside_campus_Reader> userR_W, Read_Write<Outside_campus_Reader> user, Outside_campus_Reader reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	ifstream file(filename);
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		user.ToRead(filename);
		for (unsigned i = 0; i < user.info.size(); i++)
		{
			if (user.info[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				userR_W.info.push_back(user.info[i]);//�����û���Ϣ��ȡ����
				if ((user.info.begin() + i) != user.info.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					user.info.erase(user.info.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					user.info.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				user.ToWrite(filename);//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}
	Read_Write<Book> read;//read��info����			
	int a = 0;
	Book *p = new Book[read.info.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	Book *t = p;//t�����ڶ�p ������
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		read.ToRead("book.txt");//ÿ��ѭ�����¶�ȡinfo��Ϣ
		system("cls");
		p = t;//��һ�ֽ���������P��
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
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
			cout << "û����Ҫ��ͼ�飬��淶������롣���������밴1���˳��밴�����" << endl;

			cin >> key2;
			if (key2 == "1")
				continue;
			else
			{
				cout << "���˳��˽���" << endl;
				break;
			}
		}
		else
			break;//��ѯ������˳���ѯ		
	}

	while (key2 != "1")//δ�˳�����
	{
		int t;
		if (a == 1)
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		for (unsigned i = 0; i < read.info.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read.info[i]))//���ҵ���ͬ��ַ
			{
				if (read.info[i].m_iBookCount < 0 || read.info[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read.info[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read.info[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//userR_W.info.֮ǰ�Ѿ�user.info[i]��ʵ������,��userR_W.infoֻ��һ��Ԫ��
						userR_W.info[0].readerbook.insert(userR_W.info[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						userR_W.info.push_back(reader);
					}
					userR_W.ToWrite(filename);//׷�ӵ�Reader.txt �ļ���
					break;
				}
			}
		}
		cout << "�������" << endl;
		break;

	}//���while����

	//������ɽ��ļ���գ�������д��
	ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
	file1.close();
	read.ToWrite("book.txt");
}

void library::Return(Read_Write<Teacher_Reader> returnR_W, Teacher_Reader reader, string filename)
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ
	returnR_W.ToRead(filename);//1����ȡ������Ϣ������ʾ��
	while (true)
	{
		string name;		
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < returnR_W.info.size(); i++)
		{
			if (returnR_W.info[i].putCode() == m_strRCode)//�ҵ��û�
			{
				key2 = true;
				reader = returnR_W.info[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				returnR_W.info[i].display();//����û���Ϣ
			}
		}

		//�����ڴ��û�
		if (key2 == false)
		{
			cout << "���û�������" << endl;
			break;
		}
		if (reader.readerbook.size() < 1)
		{
			cout << "����δ����" << endl;
			break;
		}

		//���û�����
		else
		{
			cout << "������Ҫ�黹��ͼ�����" << endl;
			int key3;
			cin >> key3;

			//���޸ĵ���Ϣд��Book.txt  ��  ReaderInfo.txt
			Read_Write<Book> bookR_W;
			bookR_W.ToRead("book.txt");
			for (unsigned i = 0; i < bookR_W.info.size(); i++)
			{
				if (reader.readerbook[key3].m_strBookName == bookR_W.info[i].m_strBookName && reader.readerbook[key3].m_iBookCode == bookR_W.info[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W.info[i].m_iBookCount++;
				}
			}

			if ((reader.readerbook.begin() + key3 - 1) != reader.readerbook.end())
			{
				reader.readerbook.erase(reader.readerbook.begin() + key3 - 1);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
			}
			else
			{
				reader.readerbook.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
			}
			reader.ReduceCount();//�û��Ľ�����������һ��

			ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
			file1.close();
			bookR_W.ToWrite("book.txt");//д��book.txt�ļ�

			//��reader���޸ĺ�ĵ����û���Ϣ����������Ӧ���û���Ϣ
			returnR_W.info.insert(returnR_W.info.begin() + key5, reader);//������ָ��λ�ò�������
			//���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			returnR_W.ToWrite(filename);//д���ļ�				

			cout << "�Ƿ�����黹,���밴1������������˳�" << endl;
			cin >> key4;
			if (key4 == "1" && reader.readerbook.size() > 0)//�����û������飬��ȷ�ϼ����黹ʱ
				continue;
			else
			{
				cout << "����ɹ�" << endl;
				break;//�˳��ڲ�while
			}
		}
		if (key4 != "1")
		{
			break;//�˳����while
		}
	}
}

void library::Return(Read_Write<Student_Reader> returnR_W, Student_Reader reader, string filename)
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ
	returnR_W.ToRead(filename);//1����ȡ������Ϣ������ʾ��
	while (true)
	{
		string name;	
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < returnR_W.info.size(); i++)
		{
			if (returnR_W.info[i].putCode() == m_strRCode)//�ҵ��û�
			{
				key2 = true;
				reader = returnR_W.info[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				returnR_W.info[i].display();//����û���Ϣ
			}
		}

		//�����ڴ��û�
		if (key2 == false)
		{
			cout << "���û�������" << endl;
			break;
		}
		if (reader.readerbook.size() < 1)
		{
			cout << "����δ����" << endl;
			break;
		}

		//���û�����
		else
		{
			cout << "������Ҫ�黹��ͼ�����" << endl;
			int key3;
			cin >> key3;

			//���޸ĵ���Ϣд��Book.txt  ��  ReaderInfo.txt
			Read_Write<Book> bookR_W;
			bookR_W.ToRead("book.txt");
			for (unsigned i = 0; i < bookR_W.info.size(); i++)
			{
				if (reader.readerbook[key3].m_strBookName == bookR_W.info[i].m_strBookName && reader.readerbook[key3].m_iBookCode == bookR_W.info[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W.info[i].m_iBookCount++;
				}
			}

			if ((reader.readerbook.begin() + key3 - 1) != reader.readerbook.end())
			{
				reader.readerbook.erase(reader.readerbook.begin() + key3 - 1);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
			}
			else
			{
				reader.readerbook.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
			}
			reader.ReduceCount();//�û��Ľ�����������һ��

			ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
			file1.close();
			bookR_W.ToWrite("book.txt");//д��book.txt�ļ�

			//��reader���޸ĺ�ĵ����û���Ϣ����������Ӧ���û���Ϣ
			returnR_W.info.insert(returnR_W.info.begin() + key5, reader);//������ָ��λ�ò�������
			//���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			returnR_W.ToWrite(filename);//д���ļ�				

			cout << "�Ƿ�����黹,���밴1������������˳�" << endl;
			cin >> key4;
			if (key4 == "1" && reader.readerbook.size() > 0)//�����û������飬��ȷ�ϼ����黹ʱ
				continue;
			else
			{
				cout << "����ɹ�" << endl;
				break;//�˳��ڲ�while
			}
		}
		if (key4 != "1")
		{
			break;//�˳����while
		}
	}
}

void library::Return(Read_Write<Outside_campus_Reader> returnR_W, Outside_campus_Reader reader, string filename)
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ
	returnR_W.ToRead(filename);//1����ȡ������Ϣ������ʾ��
	while (true)
	{
		string name;
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < returnR_W.info.size(); i++)
		{
			if (returnR_W.info[i].putCode() == m_strRCode)//�ҵ��û�
			{
				key2 = true;
				reader = returnR_W.info[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				returnR_W.info[i].display();//����û���Ϣ
			}
		}

		//�����ڴ��û�
		if (key2 == false)
		{
			cout << "���û�������" << endl;
			break;
		}
		if (reader.readerbook.size() < 1)
		{
			cout << "����δ����" << endl;
			break;
		}

		//���û�����
		else
		{
			cout << "������Ҫ�黹��ͼ�����" << endl;
			int key3;
			cin >> key3;

			//���޸ĵ���Ϣд��Book.txt  ��  ReaderInfo.txt
			Read_Write<Book> bookR_W;
			bookR_W.ToRead("book.txt");
			for (unsigned i = 0; i < bookR_W.info.size(); i++)
			{
				if (reader.readerbook[key3].m_strBookName == bookR_W.info[i].m_strBookName && reader.readerbook[key3].m_iBookCode == bookR_W.info[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W.info[i].m_iBookCount++;
				}
			}

			if ((reader.readerbook.begin() + key3 - 1) != reader.readerbook.end())
			{
				reader.readerbook.erase(reader.readerbook.begin() + key3 - 1);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
			}
			else
			{
				reader.readerbook.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
			}
			reader.ReduceCount();//�û��Ľ�����������һ��

			ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
			file1.close();
			bookR_W.ToWrite("book.txt");//д��book.txt�ļ�

			//��reader���޸ĺ�ĵ����û���Ϣ����������Ӧ���û���Ϣ
			returnR_W.info.insert(returnR_W.info.begin() + key5, reader);//������ָ��λ�ò�������
			//���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			returnR_W.ToWrite(filename);//д���ļ�				

			cout << "�Ƿ�����黹,���밴1������������˳�" << endl;
			cin >> key4;
			if (key4 == "1" && reader.readerbook.size() > 0)//�����û������飬��ȷ�ϼ����黹ʱ
				continue;
			else
			{
				cout << "����ɹ�" << endl;
				break;//�˳��ڲ�while
			}
		}
		if (key4 != "1")
		{
			break;//�˳����while
		}
	}
}

void library::borrowtype(int chiose1)
{
	switch (chiose1)
	{
	case 1:
	{
		Read_Write<Teacher_Reader> userR_W;
		Read_Write<Teacher_Reader> user;
		Teacher_Reader reader;
		borrow(userR_W, user, reader, "Teacher_Reader.txt");
		break;
	}
	case 2:
	{
		Read_Write<Student_Reader> userR_W;
		Read_Write<Student_Reader> user;
		Student_Reader reader;
		borrow(userR_W, user, reader, "Student_Reader.txt");
		break;
	}
	case 3:
	{
		Read_Write<Outside_campus_Reader> userR_W;
		Read_Write<Outside_campus_Reader> user;
		Outside_campus_Reader reader;
		borrow(userR_W, user, reader, "Outside_campus_Reader.txt");
		break;
	}
	default:
		break;
	}
}

void library::returntype(int chiose2)
{
	switch (chiose2)
	{
	case 1:
	{
		Read_Write<Teacher_Reader> returnR_W;
		Teacher_Reader reader;
		Return(returnR_W, reader, "Teacher_Reader.txt");
		break;
	}
	case 2:
	{
		Read_Write<Student_Reader> returnR_W;
		Student_Reader reader;
		Return(returnR_W, reader, "Student_Reader.txt");
		break;
	}
	case 3:
	{
		Read_Write<Outside_campus_Reader> returnR_W;
		Outside_campus_Reader reader;
		Return(returnR_W, reader, "Outside_campus_Reader.txt");
		break;
	}
	default:
		break;
	}
}



