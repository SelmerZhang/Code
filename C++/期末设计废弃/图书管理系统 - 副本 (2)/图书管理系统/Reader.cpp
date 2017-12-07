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