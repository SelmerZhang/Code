#include<iostream>
#include<string>
#include"ManageLogin.h"//����Ա��¼
#include"AddBook.h"//���ͼ��
#include"BookInventory.h"
#include"UpdateBook.h"
#include"Reader.h"
#include"BorrowBook.h"
#include"Read_Write.h"

using namespace std;

int main()
{
	UserType usertype;
	ManageLogin managelogin;

	if (usertype.selectCode())//ʹ���˺�ʶ�𷽷���������true��Ϊ����Ա���棻���򷵻�false��Ϊ�û���¼����
	{
		if (managelogin.getAdmin(usertype.getCode()))//��ȡ����Ա������˺ţ�����������У��
		{
			while (true)
			{

				switch (managelogin.ManageChiose())//��ȡ����Ա�Ĺ���ѡ�񣬷���Ϊ����
				{
				case 1://��ѯͼ��
				{
					BookInventory B;
					B.printBook();//����Ա���в�ѯ
					break;
				}
				case 2://����ͼ����Ϣ
				{
					UpdateBook updatebook;
					updatebook.changeBook();
					break;
				}
				case 3://ɾ��ͼ����Ϣ
				{
					UpdateBook updatebook;
					updatebook.DropBook();
					break;
				}
				case 4://���ͼ����Ϣ
				{
					AddBook addbook;
					addbook.getBook();//���ͼ��
					break;
				}
				case 5://�鿴�û���Ϣ
				{
					BorrowBook B;
					Read_Write<Reader>ReaderUser;
					ReaderUser.ToRead("Reader.txt");
					for (unsigned i = 0; i < ReaderUser.book.size(); i++)
					{
						ReaderUser.book[i].display();
					}
					break;
				}
				default:
					break;
				}
				string key;
				cout << "�Ƿ��������Ա���������밴1�����밴������˳�" << endl;
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
		}
	}

	else //���߲˵�
	{
		while (true)
		{
			switch (managelogin.ReaderChiose())
			{

			case 1://��ѯͼ��
			{
				BookInventory B;
				B.printBook();//��ѯ
				break;
			}
			case 2://����
			{
				BorrowBook Borrow;
				Borrow.borrow();
				break;
			}
			case 3://����
			{
				BorrowBook Borrow;
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
	}
	

	system("pause");

	return 0;
}