#ifndef _BORROWBOOK_H
#define _BORROWBOOK_H
#include<iostream>
#include"Read_Write.h"
#include"Reader.h"
#include"UserType.h"
using namespace std;
class BorrowBook:public Reader
{
public:
	BorrowBook();
	~BorrowBook();
	void borrow();
	void returnBook();
	void TntegrationReader();//���ļ��ڵ���Ϣ�������ϣ�ÿ�����ߵĽ��黹����Ϣд��ͬһ��reader����
	void JudgeReader(Reader& reader1,Reader& reader2);//�ж�����reader�����Ƿ�Ϊͬһ���û�
private:
	//int top;
};



#endif