#include"BorrowBook.h"

BorrowBook::BorrowBook()
{

}

BorrowBook::~BorrowBook()
{
}




//����ģ��
void BorrowBook::borrow()
{
	//1�������û���Ϣ
	//2������Ҫ���ͼ����Ϣ�������ļ��ж���������ʾ
	//3��ѡ��Ҫ���ͼ��
	//4�����Ѿ����˵�ͼ����Ϣ���µ��û��ļ�
	//5������ͼ���ļ�
	Reader reader;
	Read_Write<Reader> userR_W;
	Read_Write<Reader>user;
	reader.getReaderCode(UserType::staticCode);//���û�ID����

	ifstream file("Reader.txt");
	bool key3 = false;//������֤

	//Reader�ļ������ж��Ƿ���û��Ƿ��Ѿ����ڣ�������ڣ�����Ϣ��ȡ��������Reader.txt��ɾ�����û���Ϣ���Ա����
	if (file)
	{
		user.ToRead("Reader.txt");
		for (unsigned i = 0; i < user.book.size(); i++)
		{
			if (user.book[i].putCode() == reader.putCode())//�Ѿ��н����¼���û�
			{
				userR_W.book.push_back(user.book[i]);//�����û���Ϣ��ȡ����
				if ((user.book.begin() + i) != user.book.end())//�ٽ����û���Ϣ�������Ա�֮����²����ظ�
				{
					user.book.erase(user.book.begin() + i);//����Ԫ���Զ���ǰ�ƶ��������鳤���Զ���С,��������vector�����һ��Ԫ��
				}
				else
				{
					user.book.pop_back();//���Ҫɾ���������һ��Ԫ��Ļ�
				}
				key3 = true;//���û�
				ofstream file1("Reader.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
				file1.close();
				user.ToWrite("Reader.txt");//��д���ļ�
			}
		}
	}
	if (key3 == false)
	{
		reader.getName();//���û�����������
	}

	Read_Write<Book> read;//read��book����			
	int a = 0;
	Book *p = new Book[read.book.size()];//���ڽ��ս����Ҫ�޸ĵ�ͼ����Ϣ
	Book *t = p;//t�����ڶ�p ������
	string key2;//�����ж��Ƿ���ҳ���Ҫ���ͼ�飬���Խ������ļ������޸�
	while (true)//�ҳ���Ҫ���ͼ��
	{
		read.ToRead("book.txt");//ÿ��ѭ�����¶�ȡbook��Ϣ
		system("cls");
		p = t;//��һ�ֽ���������P��
		cout << "������������������������Ҫ���ͼ�����ƻ���ͼ���š���������������" << endl;
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
		for (unsigned i = 0; i < read.book.size(); i++)//Ƕ��̫�࣬���Ż�
		{
			if (&(p[t - a - 1]) == &(read.book[i]))//���ҵ���ͬ��ַ
			{
				if (read.book[i].m_iBookCount < 0 || read.book[i].m_iBookCount == 0)//���ж�������Ϊ0�����ɽ�
				{
					cout << "���鲻�ɽ�" << endl;
					break;
				}
				else
				{
					read.book[i].m_iBookCount--;//��Ҫ�ҵ���ַ�����ļ������޸�
					reader.AddCount();
					reader.readerbook.push_back(read.book[i]);//��������Ϣд���û���Ϣ
					//���û���Ϣд���ļ�
					reader.getCount();
					if (key3)//���û�֮ǰ�Ѿ������
					{
						//userR_W.book.֮ǰ�Ѿ�user.book[i]��ʵ������,��userR_W.bookֻ��һ��Ԫ��
						userR_W.book[0].readerbook.insert(userR_W.book[0].readerbook.end(), reader.readerbook.begin(), reader.readerbook.end());
					}
					else//���û�֮ǰδ�����
					{
						userR_W.book.push_back(reader);
					}
					userR_W.ToWrite("Reader.txt");//׷�ӵ�Reader.txt �ļ���
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

	/*delete[] p;
	p = NULL;*/
}



//����
void BorrowBook::returnBook()
{
	//1����ȡ������Ϣ������ʾ��
	//2��ƥ���û�����ID
	//3����ʾ������Ϣ
	//4��ѡ��Ҫ��ͼ��
	//5���޸Ķ�����Ϣ
	//6���޸��ļ���Ϣ
	Read_Write<Reader> returnR_W;
	returnR_W.ToRead("Reader.txt");//1����ȡ������Ϣ������ʾ��
	while (true)
	{
		Reader reader;
		string key1, name;
		key1 = reader.getReaderCode(UserType::staticCode);//���û�ID����		
		string key4;//�ж��Ƿ��������vector<int>key7;//��¼�û���vector���е�λ��
		int key5;
		bool key2 = false;//�ж��û��Ƿ����
		for (unsigned i = 0; i < returnR_W.book.size(); i++)
		{
			if (returnR_W.book[i].putCode() == key1)//�ҵ��û�
			{
				key2 = true;
				reader = returnR_W.book[i];
				//cout << "��ѯ���ĵ� " << reader.size() << " λ�û�" << endl;
				key5 = i;//��¼�û���vector���е�λ��
				returnR_W.book[i].display();//����û���Ϣ
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
			for (unsigned i = 0; i < bookR_W.book.size(); i++)
			{
				if (reader.readerbook[key3].m_strBookName == bookR_W.book[i].m_strBookName && reader.readerbook[key3].m_iBookCode == bookR_W.book[i].m_iBookCode)//��book.txt ���ҵ��û������Ǳ���
				{
					bookR_W.book[i].m_iBookCount++;
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
			returnR_W.book.insert(returnR_W.book.begin() + key5, reader);//������ָ��λ�ò�������
            //���޸ĵ���Ϣд��ReaderInfo.txt
			ofstream file2("Reader.txt", ios::trunc | ios::out);//���ļ�����Ա�����д��
			file2.close();
			returnR_W.ToWrite("Reader.txt");//д���ļ�				

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