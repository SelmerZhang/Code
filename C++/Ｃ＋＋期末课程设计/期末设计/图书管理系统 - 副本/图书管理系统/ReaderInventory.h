#ifndef _READERINVENTORY_H
#define _READERINVENTORY_H
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include"Read_Write.h"
#include"Reader.h"
using namespace std;

class ReaderInventory :virtual public Reader
{
public:
	ReaderInventory();
	void printReader();
	~ReaderInventory();
};



#endif