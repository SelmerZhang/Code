#include<iostream>
#include"UserType.h"

using namespace std;

//UserType::UserType()
//{
//	m_strCode = "01";//Ĭ�ϵ�¼Ϊ����Ա
//}

UserType::~UserType()
{

}
string UserType::staticCode = "0001";

bool UserType::selectCode()//�˺������ж�
{
	string code;
	while (true)
	{
		cout << "��������λ������Ա�˺ţ������û���λ���˺ţ�" << endl;
		cin >> code;
		m_strCode = code;
		if (m_strCode.size() == 2)//����Ա��λ���˺�
		{			
			return true;
			break;
		}

		if (m_strCode.size() == 4)//�û���λ���˺�
		{			
			staticCode = m_strCode;
			//cout << "�ж��˺�����staticCode:" << staticCode << endl;
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

void UserType::display()
{
	cout << m_strCode << endl;
}


string UserType::getCode()
{
	return m_strCode;
}
