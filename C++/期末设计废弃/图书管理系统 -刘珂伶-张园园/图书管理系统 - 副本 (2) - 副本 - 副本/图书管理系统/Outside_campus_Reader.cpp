#include"Outside_campus_Reader.h"

void Outside_campus_Reader::display()
{
	cout << "����һλУ����ߣ����ߵ�סַ�ǣ�" << m_strAdress << endl;
	cout << "���ߵĵ绰�����ǣ�" << m_strTelephoneNumber << endl;
	Reader::display();
}

istream& operator>>(istream &is, Outside_campus_Reader &outside_campus_Reader)
{
	Book book1;
	is >> outside_campus_Reader.m_strAdress >> outside_campus_Reader.m_strTelephoneNumber >> outside_campus_Reader.m_strCode >> outside_campus_Reader.m_strName >> outside_campus_Reader.UserBookCount;
	outside_campus_Reader.readerbook.clear();//����ջᷢ�����벻���Ĵ���
	for (int i = 0; i < outside_campus_Reader.UserBookCount; i++)
	{
		is >> book1.m_strBookName >> book1.m_iBookCode >> book1.m_iBookCount;
		outside_campus_Reader.readerbook.push_back(book1);
	}
	return is;
}

ostream& operator<<(ostream &os, Outside_campus_Reader &outside_campus_Reader)
{
	os << outside_campus_Reader.m_strAdress << ' ' << outside_campus_Reader.m_strTelephoneNumber << ' ' << outside_campus_Reader.m_strCode << ' ' << outside_campus_Reader.m_strName << ' ' << outside_campus_Reader.UserBookCount;
	for (unsigned i = 0; i < outside_campus_Reader.readerbook.size(); i++)
	{
		os << ' ' << outside_campus_Reader.readerbook[i].m_strBookName << ' ' << outside_campus_Reader.readerbook[i].m_iBookCode << ' ' << outside_campus_Reader.readerbook[i].m_iBookCount;
	}
	os << endl;
	return os;
}
