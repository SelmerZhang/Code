#include<iostream>
#include<string>
#include"library.h"

using namespace std;

int main()
{
	library LIB;

	if (LIB.usertype()==true)//ʹ���˺�ʶ�𷽷���������true��Ϊ����Ա���棻���򷵻�false��Ϊ�û���¼����
	{		
			while (true)
			{

				switch (LIB.managelogin())//��ȡ����Ա�Ĺ���ѡ�񣬷���Ϊ����
				{
				case 1://��ѯͼ��
				{
					LIB.BookInventory();
					break;
				}
				case 2://����ͼ����Ϣ
				{
					LIB.changeBook();
					break;
				}
				case 3://ɾ��ͼ����Ϣ
				{
					LIB.DropBook();
					break;
				}
				case 4://���ͼ����Ϣ
				{
					LIB.AddBook();//���ͼ��
					break;
				}
				case 5://�鿴�û���Ϣ
				{
					LIB.checktype();
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

	else //���߲˵�
	{
		cout << "lalalalalllllllll";
		int chiose=LIB.ReaderType();
		
		while (true)
		{
			switch (LIB.Readerchiose())
			{

			case 1://��ѯͼ��
			{
				LIB.BookInventory();
				break;
			}
			case 2://����
			{
				LIB.borrowtype(chiose);
				break;
			}
			case 3://����
			{
				LIB.returntype(chiose);
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