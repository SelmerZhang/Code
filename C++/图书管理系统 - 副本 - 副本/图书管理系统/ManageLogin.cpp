#include<iostream>
#include"ManageLogin.h"

using namespace std;

ManageLogin::ManageLogin()
{
}

ManageLogin::~ManageLogin()
{
}

bool ManageLogin::getAdmin(string code)
{
	cout << "hello Manage�� " << code << endl;

	string admin;
	while (1)
	{
		cout << "���������룺 ";
		cin >> admin;
		/*cout << "m_strCode: " << m_strAdmin << "  " << m_strAdmin.size() << endl;
		cout << "admin: " << admin << "  " << admin.size() << endl;*/
		if (admin == code)
		{
			cout << "��ӭ�������ϵͳ" << endl;
			return true;
			break;
		}
		else
		{
			cout << "����������벻��ȷ������������"<<endl;
			cout << "�Ƿ��������룬���밴:Y�����밴������˳�" << endl;
			string key;
			cin >> key;
			if (key=="y"||key=="Y")
			continue;
			else
			{   cout << "��ѡ�����˳�" << endl;
			    return false;
				break;
			}
		}
	}
}

int ManageLogin::ManageChiose()
{
	system("cls");//����
	cout << "��������ѡ������Ҫ�����Ĳ�������������Ӧ��š�����" <<endl;
	cout << "��������������������1���鿴ͼ�顤������������������" << endl;
	cout << "��������������������2������ͼ�顤������������������" << endl;
	cout << "��������������������3��ɾ��ͼ�顤������������������" << endl;
	cout << "��������������������4������ͼ�顤������������������" << endl;
	cout << "��������������������5��������Ϣ��������������������" << endl;
	int chiose;
	while(true)
	{
    cin >> chiose;
	if (chiose == 1 || chiose == 2 || chiose == 3 || chiose == 4||chiose==5)
	{
		return chiose;
		break;
	}
	else
	{
		cout << "�������ѡ����ȷ������������"<<endl;
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

int ManageLogin::ReaderChiose()//����ѡ��
{
	system("cls");//����
	cout << "�û���" << UserType::staticCode<<endl;
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