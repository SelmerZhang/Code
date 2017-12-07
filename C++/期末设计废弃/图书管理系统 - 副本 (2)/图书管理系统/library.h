#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include<string>
#include<fstream>
#include"Read_Write.h"
#include"Teacher_Reader.h"
#include"Student_Reader.h"
#include"Outside_campus_Reader.h"
#include"Book.h"
using namespace std;

class library
{
public:
	library();
	~library();
	bool usertype();
	int managelogin();
	void BookInventory();	
	void changeBook();//�޸�ͼ����Ϣ
	void DropBook();//ɾ��ͼ����Ϣ
	void AddBook();
	int ReaderType();
	int Readerchiose();
	template<class R>
	void borrow(Read_Write<R> userR_W, Read_Write<R> user,R reader,string filename);
	template<class T>
	void Return(Read_Write<T> returnR_W, T reader, string filename);
	void borrowtype(int chiose);	
	void returntype(int chiose);
	void checktype();
private:
    static string m_strRCode;
};

template<class R>
void library::borrow(Read_Write<R> userR_W, Read_Write<R> user, R reader, string filename)
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�

	reader.getReaderCode(library::m_strRCode);//���û�ID����
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

template<class T>
void library::Return(Read_Write<T> returnR_W, T reader, string filename)
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
		string key1, name;
		key1 = reader.getReaderCode(library::m_strRCode);//���û�ID����		
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < returnR_W.info.size(); i++)
		{
			if (returnR_W.info[i].putCode() == key1)//�ҵ��û�
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

void library::borrowtype(int chiose)
{
	switch (chiose)
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

void library::returntype(int chiose)
{
	switch (chiose)
	{
	case 1:
	{
		Read_Write<Teacher_Reader> returnR_W;
		Teacher_Reader reader;
		Return(returnR_W,reader, "Teacher_Reader.txt");
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
		Return(returnR_W,  reader, "Outside_campus_Reader.txt");
		break;
	}
	default:
		break;
	}
}




#endif