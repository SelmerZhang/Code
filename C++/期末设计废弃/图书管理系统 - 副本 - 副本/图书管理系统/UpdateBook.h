#ifndef _UPDATEBOOK_H
#define _UPDATEBOOK_H

#include"BookInventory.h"
#include"Read_Write.h"
class UpdateBook:public Book
{
public:
	UpdateBook();
	~UpdateBook();
	void changeBook();//�޸�ͼ����Ϣ
	void DropBook();//ɾ��ͼ����Ϣ
private:
	int top;//���ڱ�ǽ�Ҫ��ɾ�����Ǳ���
};

#endif 