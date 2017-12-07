#include"Reader.h"

Reader::Reader()
{
	UserBookCount = readerbook.size();
}

Reader::~Reader()
{

}

string Reader::getReaderCode(string code)
{
	m_strCode=code;	
	return m_strCode;
}

void Reader::getName()
{
	cout << "��������������" << endl;
	string name;
	cin >> name;
	m_strName = name;
}

void Reader::getBook(Book book)
{
	readerbook.push_back(book);
}

void Reader::getCount()
{
	UserBookCount = readerbook.size();
}

void Reader::AddCount()
{
	UserBookCount++;
}

void Reader::ReduceCount()
{
	UserBookCount--;
}
istream& operator>>(istream &is, Reader &reader)//read
{
	Book book1;
	is >> reader.m_strCode >> reader.m_strName >> reader.UserBookCount;
	reader.readerbook.clear();//����ջᷢ�����벻���Ĵ���
 	for (int i = 0; i < reader.UserBookCount; i++)
	{		
		is >> book1.m_strBookName >> book1.m_iBookCode >> book1.m_iBookCount;		
		reader.readerbook.push_back(book1);
	}
	return is;
}

ostream& operator<<(ostream &os, Reader &reader)//write��writeǰһ��Ҫ�ȳ�ʼ��vector<Book> readerbook��Ҫ��Ȼ�ò�������
{
	os << reader.m_strCode << ' ' << reader.m_strName << ' ' << reader.UserBookCount;
	for (unsigned i = 0; i < reader.readerbook.size(); i++)
	{
		os << ' ' << reader.readerbook[i].m_strBookName << ' ' << reader.readerbook[i].m_iBookCode << ' ' << reader.readerbook[i].m_iBookCount;
	}
	os << endl;
	return os;
}


void Reader::display()
{
	cout << "�û�ID��" << m_strCode << endl;
	cout << "�û�����" << m_strName << endl;
	for (unsigned i = 0; i < readerbook.size(); i++)
	{
       cout << "��ĵ� "<<i+1<<" ������Ϣ:" <<endl;
	   readerbook[i].displayBook();
	}
	UserBookCount = readerbook.size();
	cout << "һ������ " << UserBookCount << " ����" << endl;
	cout << endl;
}

string Reader::putName()
{
	return m_strName;
}
string Reader::putCode()
{
	return m_strCode;
}