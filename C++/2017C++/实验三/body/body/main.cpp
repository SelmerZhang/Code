#include<iostream>
#include<vector>
#include"body.h"
using namespace std;

//���ն���ĵ��÷�������Ⲣ����ʹ����Ԫ��������������صķ���
//��д���򣬶���body�࣬��¼����ѧ�������彡��״����Ҫ��
//����ʹ�ö������飻
//��body������ݳ�Ա�ο������Ŀ��
//��body��ĺ�����Ա�����������⣬Ӧ�н���״�������ۡ�


int main()
{
	body b[3];
	for (int i = 0; i < 3;i++)
	{ 
	b[i].getbody();
	cheakbody(b[0]);
	}

	getchar();
	return 0;
}
