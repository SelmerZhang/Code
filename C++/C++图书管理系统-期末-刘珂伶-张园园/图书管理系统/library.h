#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Teacher_Reader.h"
#include"Student_Reader.h"
#include"Outside_campus_Reader.h"
#include"Book.h"
using namespace std;

class library
{
public:
	library();
	~library();
	bool usertype();
	int managelogin();
	void BookInventory();	
	void changeBook();//�޸�ͼ����Ϣ
	void DropBook();//ɾ��ͼ����Ϣ
	void AddBook();
	int ReaderType();
	int Readerchiose();
	void borrow(Teacher_Reader reader, string filename);
	void borrow(Student_Reader reader, string filename);
	void borrow(Outside_campus_Reader reader, string filename);
	void Return(Teacher_Reader reader, string filename);
	void Return(Student_Reader reader, string filename);
	void Return(Outside_campus_Reader reader, string filename);
	void borrowtype(int chiose1);	
	void returntype(int chiose2);
	void checktype();
	template<typename T>
	vector<T> Read(string txtname);
	template<typename T>
	void Write(string txtname,vector<T> info);
	
private:
    static int m_strRCode;
	
};




template<typename T>
vector<T> library::Read(string txtname)
{	
		T b;
		vector<T> info;
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
		return info;
}

template<typename T>
void library::Write(string txtname,vector<T> info)
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

		cout << " �ɹ�������Ϣ" << endl;
	}
	file.close();
}






#endif