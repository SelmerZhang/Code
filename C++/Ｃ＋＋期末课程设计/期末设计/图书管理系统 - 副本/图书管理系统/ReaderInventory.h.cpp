#include"ReaderInventory.h"

ReaderInventory::ReaderInventory()
{

}
void ReaderInventory::printReader()
{
	Read_Write<Reader>ReaderUser;
	ReaderUser.ToRead("Reader.txt");
	if (ReaderUser.book.size() == 0)
	{
		cout << "û�ж��߽���" << endl;
	}
	else
	{
		for (unsigned i = 0; i < ReaderUser.book.size(); i++)
		{
			ReaderUser.book[i].display();
		}
	}
}

ReaderInventory::~ReaderInventory()
{

}

