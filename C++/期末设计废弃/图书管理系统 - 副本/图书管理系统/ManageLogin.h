#ifndef _MANAGELOGIN_H
#define _MANAGELOGIN_H

#include<string>
#include"UserType.h"
using namespace std;
//��֤����Ա����
class ManageLogin
{
public:
	ManageLogin();
	~ManageLogin();
	bool getAdmin(string code);//�������Ա���벢�ж������Ƿ���ȷ
	int ManageChiose();
	int ReaderChiose();
private:
	string m_strAdmin;
};

#endif