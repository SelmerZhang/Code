#ifndef _USERTYPE_H
#define _USERTYPE_H
//�ж��û�����
#include<string>
using namespace std;

class UserType
{
public:
	virtual ~UserType();
	bool selectCode();
	void display();
	string getCode();
	string m_strCode;
	static string staticCode;//���ڼ�¼����ID��
};

#endif

