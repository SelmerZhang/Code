#ifndef _READTXT_H
#define _READTXT_H
#include<iostream>
#include<vector>
#include<fstream>
#include"Outside_campus_Reader.h"
#include"Teacher_Reader.h"
#include"Student_Reader.h"
using namespace std;

template<class T>
class Read_Write//���ļ����ݶ���book������
{
public:
	Read_Write();
	~Read_Write();
	void ToWrite(string txtname);
	void ToRead(string txtname);
	void getBook(T t);
	vector<T> info;
};
template<class T>
Read_Write<T>::Read_Write()
{

}
template<class T>
void Read_Write<T>::getBook(T t)
{
	book.push_back(t);
}
template<class T>
void Read_Write<T>::ToRead(string txtname)
{
	T b;
	ifstream file(txtname, ios::in);//�Զ��ķ�ʽ��ȡ�ļ�
	while (!file.eof())//��ȡtxt���ݵ��������У�eof�ж��Ƿ�����ļ�β��
	{
		if (!file)
		{
			cout << "BookInventory:�ļ�δ������" << endl;
			break;
		}
		file >> b;
		info.push_back(b);
	}
	info.pop_back();//�����һ���ظ���Ԫ�鵯��
	file.close();
}
template<class T>

void Read_Write<T>::ToWrite(string txtname)//��������׷�ӵķ�ʽ����txt
{
	ofstream file(txtname, ios::app | ios::out);
	if (!file)
	{
		cout << "�ļ���ʧ��" << endl;
	}
	else
	{
		for (unsigned i = 0; i < info.size(); i++)
		{
			file << info[i];  
		}
		
		 cout<<" �ɹ�������Ϣ" << endl;
	}

	file.close();
}
template<class T>
Read_Write<T>::~Read_Write()
{
}

#endif