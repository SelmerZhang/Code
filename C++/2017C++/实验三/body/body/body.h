#ifndef BODY_H_
#define BODY_H_

#include<iostream>
#include<string>
using namespace std;

//���ն���ĵ��÷�������Ⲣ����ʹ����Ԫ��������������صķ���
//��д���򣬶���body�࣬��¼����ѧ�������彡��״����Ҫ��
//����ʹ�ö������飻
//��body������ݳ�Ա�ο������Ŀ��
//��body��ĺ�����Ա�����������⣬Ӧ�н���״�������ۡ�
class body
{
public:
	body();
	body(char name,int height,int weight);
	void getbody();
	friend void cheakbody(body&);
	~body();
private:
	string Strname;
	int Iheight;
	int Iweight;
};

#endif