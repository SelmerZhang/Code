#include"library.h"
using namespace std;

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
		if (m_strRCode > 9 && m_strRCode < 100)//����Ա��λ���˺�
		{
			return true;
			break;
		}

		if (m_strRCode>99 && m_strRCode < 10000)//�û���λ���˺�
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
	vector<Book> read(Read<Book>("book.txt"));
	cout << "������������������ѯ����ͼ���밴1����������������" << endl;
	cout << "��������������������ȷ��ѯ�밴2������������������" << endl;
	cout << "��������������������������˳�������������������" << endl;
	string key;
	cin >> key;
	while (true)
	{
		if (key == "1")
		{
			for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
			{
				read[i].displayBook();
			}
			break;
		}
		if (key == "2")//�Զ���ģ����ѯ
		{
			cout << "��������������������Ҫ��ѯ��ͼ�����ƻ��š�����������" << endl;
			string key1;
			cin >> key1;
			int a = 0;
			for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
			{
				if ((read[i].m_strBookName.find(key1) != string::npos) || (read[i].m_iBookCode.find(key1) != string::npos))
				{
					cout << "�� ��" << key1 << "�� ��ص�ͼ����Ϣ:";
					read[i].displayBook();
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
	vector<Book> read(Read<Book>("book.txt"));
	int a = 0;
	Book *p = new Book[100];//���ڽ�����Ҫ�޸ĵ�ͼ��
	string key2;//�����ж��Ƿ���ҳ���Ҫ�޸ĵ�ͼ�飬���ж��Ƿ���������޸�
	while (true)//�ҳ���Ҫ�޸ĵ�ͼ��
	{
		system("cls");
		cout << "��������������������������µ�ͼ�����ƻ���ͼ���š���������������" << endl;
		string key;
		cin >> key;
		for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
		{
			if ((read[i].m_strBookName.find(key) != string::npos) || (read[i].m_iBookCode.find(key) != string::npos))
			{
				a++;//��¼��ѯ���ı���
				cout << "�� ��" << key << "�� ��صĵ� " << a << " ��ͼ����Ϣ:" << endl;
				read[i].displayBook();
				cout << endl;
				p = &(read[i]);
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
		for (unsigned i = 0; i < read.size(); i++)
		{
			if (&(p[t - a]) == &(read[i]))//��ַ��ͬʱ	
			{
				swap(read[i], (p[t - a]));
				cout << "�޸ĳɹ�" << endl;

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
	Write("book.txt", read);
	//delete[] p;
	//p = NULL;//�ڴ��ͷų������⣬����������
}

void library::DropBook()
{
	//1������ͼ����Ϣ�����ϱ�Ŵ�ӡ
	//2��ѡ��Ҫɾ����ͼ����
	//3��ɾ��ͼ��,ע��βָ��ı仯
	//4�������ļ�
	vector<Book> read(Read<Book>("book.txt"));
	int top = 0;
	for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
	{
		top++;
		cout << "�� " << top << " ��ͼ��" << endl;
		read[i].displayBook();
	}
	int key1;
	while (true)
	{
		cout << "��ѡ����Ҫɾ����ͼ�����" << endl;
		cin >> key1;
		if (key1 >= 0 && key1 <= top)
		{
			if ((read.begin() + (key1 - 1)) != read.end())
			{
				read.erase(read.begin() + (key1 - 1));//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
			}
			else
			{
				read.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
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
	Write("book.txt", read);
}

void library::AddBook()
{

	//1������ͼ����Ϣ
	//2����ͼ����Ϣд���ļ�
	string name;
	string code;
	int count;
	string key;
	vector<Book> read(Read<Book>("book.txt"));
	while (1)
	{
		cout << "������ͼ������" << endl;
		cin >> name;
		cout << "������ͼ����" << endl;
		cin >> code;
		cout << "���������ͼ�����Ŀ" << endl;
		cin >> count;
		Book b(name, code, count);
		read.push_back(b);
		cout << "�Ƿ����¼��ͼ�飬�ǣ��밴y(Y)���񣺰�������˳�" << endl;
		cin >> key;
		if (key != "y" && key != "Y")//�ж��Ƿ��������
			break;
	}
	ofstream file1("book.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
	file1.close();
	Write("book.txt", read);//�����ļ�
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
		vector<Teacher_Reader>read(Read<Teacher_Reader>("Teacher_Reader.txt"));
	for (unsigned i = 0; i < read.size(); i++)
	{
		read[i].display();
	}
	break;
	}
	case 2:
	{
		vector<Student_Reader> read(Read<Student_Reader>("Student_Reader.txt"));

		for (unsigned i = 0; i < read.size(); i++)
		{
			read[i].display();
		}
		break;
	}
	case 3:
	{
		vector<Outside_campus_Reader> read(Read<Outside_campus_Reader>("Outside_campus_Reader.txt"));
		for (unsigned i = 0; i < read.size(); i++)
		{
			read[i].display();
		}
		break;
	}
	default:
		break;
	}
}

void library::borrow(Teacher_Reader reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	vector<Teacher_Reader> Teacher;
	ifstream file(filename);
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		vector<Teacher_Reader> teacher_reader(Read<Teacher_Reader>(filename));
		for (unsigned i = 0; i < teacher_reader.size(); i++)
		{
			if (teacher_reader[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				Teacher.push_back(teacher_reader[i]);//�����û���Ϣ��ȡ����
				if ((teacher_reader.begin() + i) != teacher_reader.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					teacher_reader.erase(teacher_reader.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					teacher_reader.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				Write(filename, teacher_reader);//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}

	vector<Book> read(Read<Book>("book.txt"));
	int a = 0;
	Book *p = new Book[read.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		system("cls");
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
		string key;
		cin >> key;
		for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
		{
			if ((read[i].m_strBookName.find(key) != string::npos) || (read[i].m_iBookCode.find(key) != string::npos))
			{
				a++;//��¼��ѯ���ı���
				cout << "�� ��" << key << "�� ��صĵ� " << a << " ��ͼ����Ϣ:" << endl;
				read[i].displayBook();
				cout << endl;
				p = &(read[i]);
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
		if (a == 1)//ֻ��ѯ��һ�������ص���
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		if (key3 == true)//���û����ж��Ƿ��ѽ������
		{
			for (unsigned i = 0; i < Teacher[0].readerbook.size(); i++)
			{
				for (unsigned i = 0; i < read.size(); i++)
				{
					if (&(p[t - a - 1]) == &(read[i]) && Teacher[0].readerbook[i].m_iBookCode == read[i].m_iBookCode)//�ô˻��ѽ���Ȿ���ˣ����ٽ�
					{
						cout << "��������δ�黹,�����ٽ����" << endl;
						break;
					}
				}
			}
		}

		for (unsigned i = 0; i < read.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read[i]))//���ҵ���ͬ��ַ
			{
				if (read[i].m_iBookCount < 0 || read[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//Teacher֮ǰ�Ѿ�read[i]��ʵ������,��Teacherֻ��һ��Ԫ��
						Teacher[0].readerbook.insert(Teacher[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						Teacher.push_back(reader);
					}
					Write(filename, Teacher);//׷�ӵ�Reader.txt �ļ���
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
	Write("book.txt", read);
}

void library::borrow(Student_Reader reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	vector<Student_Reader> Student;
	ifstream file(filename);
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		vector<Student_Reader> student_reader(Read<Student_Reader>(filename));
		for (unsigned i = 0; i < student_reader.size(); i++)
		{
			if (student_reader[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				Student.push_back(student_reader[i]);//�����û���Ϣ��ȡ����
				if ((student_reader.begin() + i) != student_reader.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					student_reader.erase(student_reader.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					student_reader.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				Write(filename, student_reader);//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}

	vector<Book> read(Read<Book>("book.txt"));
	int a = 0;
	Book *p = new Book[read.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		system("cls");
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
		string key;
		cin >> key;
		for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
		{
			if ((read[i].m_strBookName.find(key) != string::npos) || (read[i].m_iBookCode.find(key) != string::npos))
			{
				a++;//��¼��ѯ���ı���
				cout << "�� ��" << key << "�� ��صĵ� " << a << " ��ͼ����Ϣ:" << endl;
				read[i].displayBook();
				cout << endl;
				p = &(read[i]);
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
		if (a == 1)//ֻ��ѯ��һ�������ص���
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		for (unsigned i = 0; i < read.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read[i]))//���ҵ���ͬ��ַ
			{
				if (read[i].m_iBookCount < 0 || read[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//Student֮ǰ�Ѿ�read[i]��ʵ������,��Studentֻ��һ��Ԫ��
						Student[0].readerbook.insert(Student[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						Student.push_back(reader);
					}
					Write(filename, Student);//׷�ӵ�Reader.txt �ļ���
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
	Write("book.txt", read);
}

void library::borrow(Outside_campus_Reader reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	vector<Outside_campus_Reader> Outside;
	ifstream file(filename);
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		vector<Outside_campus_Reader> outside_campus_reader(Read<Outside_campus_Reader>(filename));
		for (unsigned i = 0; i < outside_campus_reader.size(); i++)
		{
			if (outside_campus_reader[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				Outside.push_back(outside_campus_reader[i]);//�����û���Ϣ��ȡ����
				if ((outside_campus_reader.begin() + i) != outside_campus_reader.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					outside_campus_reader.erase(outside_campus_reader.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					outside_campus_reader.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				Write(filename, outside_campus_reader);//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}

	vector<Book> read(Read<Book>("book.txt"));
	int a = 0;
	Book *p = new Book[read.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		system("cls");
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
		string key;
		cin >> key;
		for (unsigned i = 0; i < read.size(); i++)//��ӡ��txt�ж�ȡ�Ľ��
		{
			if ((read[i].m_strBookName.find(key) != string::npos) || (read[i].m_iBookCode.find(key) != string::npos))
			{
				a++;//��¼��ѯ���ı���
				cout << "�� ��" << key << "�� ��صĵ� " << a << " ��ͼ����Ϣ:" << endl;
				read[i].displayBook();
				cout << endl;
				p = &(read[i]);
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
		if (a == 1)//ֻ��ѯ��һ�������ص���
		{
			t = 1;
		}
		else
		{
			cout << "��������Ҫ���ͼ������" << endl;
			cin >> t;
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		for (unsigned i = 0; i < read.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read[i]))//���ҵ���ͬ��ַ
			{
				if (read[i].m_iBookCount < 0 || read[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//Outside֮ǰ�Ѿ�read[i]��ʵ������,��Outsideֻ��һ��Ԫ��
						Outside[0].readerbook.insert(Outside[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						Outside.push_back(reader);
					}
					Write(filename, Outside);//׷�ӵ�Reader.txt �ļ���
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
	Write("book.txt", read);
}

void library::Return(Teacher_Reader reader, string filename)
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ

	vector<Teacher_Reader> teacher_reader(Read<Teacher_Reader>(filename));
	while (true)
	{
		string name;
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;//��¼�û����ļ��е�λ��
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < teacher_reader.size(); i++)
		{
			if (teacher_reader[i].putCode() == m_strRCode)//�ҵ��û�
			{
				key2 = true;
				reader = teacher_reader[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				teacher_reader[i].display();//����û���Ϣ
			}
		}

		//�����ڴ��û�
		if (key2 == false)
		{
			cout << "���û������ڣ�����δ����" << endl;
			break;
		}
		if (reader.readerbook.size() < 1)
		{
			cout << "����δ����" << endl;
			break;
		}

		//���û�����,����δ����
		else
		{
			cout << "������Ҫ�黹��ͼ�����" << endl;
			int key3;
			cin >> key3;

			//���޸ĵ���Ϣд��Book.txt  ��  ReaderInfo.txt
			vector<Book> bookR_W(Read<Book>("book.txt"));
			for (unsigned i = 0; i < bookR_W.size(); i++)
			{
				if (reader.readerbook[key3 - 1].m_strBookName == bookR_W[i].m_strBookName && reader.readerbook[key3 - 1].m_iBookCode == bookR_W[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W[i].m_iBookCount++;
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
			Write("book.txt", bookR_W);//д��book.txt�ļ�

			//��reader���޸ĺ�ĵ����û���Ϣ����������Ӧ���û���Ϣ
			teacher_reader.insert(teacher_reader.begin() + key5, reader);//������ָ��λ�ò�������
			//���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			Write(filename, teacher_reader);//д���ļ�				

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

void library::Return(Student_Reader reader, string filename)
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ

	vector<Student_Reader> student_reader(Read<Student_Reader>(filename));
	while (true)
	{
		string name;
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;//��¼�û����ļ��е�λ��
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < student_reader.size(); i++)
		{
			if (student_reader[i].putCode() == m_strRCode)//�ҵ��û�
			{
				key2 = true;
				reader = student_reader[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				student_reader[i].display();//����û���Ϣ
			}
		}

		//�����ڴ��û�
		if (key2 == false)
		{
			cout << "���û������ڣ�����δ����" << endl;
			break;
		}
		if (reader.readerbook.size() < 1)
		{
			cout << "����δ����" << endl;
			break;
		}

		//���û�����,����δ����
		else
		{
			cout << "������Ҫ�黹��ͼ�����" << endl;
			int key3;
			cin >> key3;

			//���޸ĵ���Ϣд��Book.txt  ��  ReaderInfo.txt
			vector<Book> bookR_W(Read<Book>("book.txt"));
			for (unsigned i = 0; i < bookR_W.size(); i++)
			{
				if (reader.readerbook[key3 - 1].m_strBookName == bookR_W[i].m_strBookName && reader.readerbook[key3 - 1].m_iBookCode == bookR_W[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W[i].m_iBookCount++;
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
			Write("book.txt", bookR_W);//д��book.txt�ļ�

			//��reader���޸ĺ�ĵ����û���Ϣ����������Ӧ���û���Ϣ
			student_reader.insert(student_reader.begin() + key5, reader);//������ָ��λ�ò�������
			//���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			Write(filename, student_reader);//д���ļ�				

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

void library::Return(Outside_campus_Reader reader, string filename)
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ

	vector<Outside_campus_Reader> outside_campus_reader(Read<Outside_campus_Reader>(filename));
	while (true)
	{
		string name;
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;//��¼�û����ļ��е�λ��
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < outside_campus_reader.size(); i++)
		{
			if (outside_campus_reader[i].putCode() == m_strRCode)//�ҵ��û�
			{
				key2 = true;
				reader = outside_campus_reader[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				outside_campus_reader[i].display();//����û���Ϣ
			}
		}

		//�����ڴ��û�
		if (key2 == false)
		{
			cout << "���û������ڣ�����δ����" << endl;
			break;
		}
		if (reader.readerbook.size() < 1)
		{
			cout << "����δ����" << endl;
			break;
		}

		//���û�����,����δ����
		else
		{
			cout << "������Ҫ�黹��ͼ�����" << endl;
			int key3;
			cin >> key3;

			//���޸ĵ���Ϣд��Book.txt  ��  ReaderInfo.txt
			vector<Book> bookR_W(Read<Book>("book.txt"));
			for (unsigned i = 0; i < bookR_W.size(); i++)
			{
				if (reader.readerbook[key3 - 1].m_strBookName == bookR_W[i].m_strBookName && reader.readerbook[key3 - 1].m_iBookCode == bookR_W[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W[i].m_iBookCount++;
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
			Write("book.txt", bookR_W);//д��book.txt�ļ�

			//��reader���޸ĺ�ĵ����û���Ϣ����������Ӧ���û���Ϣ
			outside_campus_reader.insert(outside_campus_reader.begin() + key5, reader);//������ָ��λ�ò�������
			//���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2(filename, ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			Write(filename, outside_campus_reader);//д���ļ�				

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
		Teacher_Reader reader;
		borrow(reader, "Teacher_Reader.txt");
		break;
	}
	case 2:
	{
		Student_Reader reader;
		borrow(reader, "Student_Reader.txt");
		break;
	}
	case 3:
	{
		Outside_campus_Reader reader;
		borrow(reader, "Outside_campus_Reader.txt");
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
		Teacher_Reader reader;
		Return(reader, "Teacher_Reader.txt");
		break;
	}
	case 2:
	{
		Student_Reader reader;
		Return(reader, "Student_Reader.txt");
		break;
	}
	case 3:
	{
		Outside_campus_Reader reader;
		Return(reader, "Outside_campus_Reader.txt");
		break;
	}
	default:
		break;
	}
}



