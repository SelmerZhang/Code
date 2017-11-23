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
};



#endif