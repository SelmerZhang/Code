#ifndef _BOOKINVENTORY_H
#define _BOOKINVENTORY_H
//ͼ��⣬���ļ�����д��ͼ������
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include"Read_Write.h"
using namespace std;

class BookInventory
{
public:
	BookInventory();
	void printBook();
	~BookInventory();
};

#endif