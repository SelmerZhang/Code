#include<iostream>
#include<stdlib.h>
using namespace std;

class Coordinate
{
public:
	int x;
	int y;
	void printx()
	{
		cout<<x<<endl;
	}
	void printy()
	{
		cout<<y<<endl;
	}
};

int main(void)
{
    Coordinate Coor;
	Coor.x=10;
	Coor.y=20;
	Coor.printx();
	Coor.printy();


	Coordinate *p=new Coordinate();
	if(NULL==p)
	{
		return 0;//��ȡ�ڴ�ʧ�ܣ��˳�
	}
	p->x =100;
	p->y =200;
	p->printx();
	p->printy();

	delete p;//�ͷ��ڴ�
	p=NULL;//�ͷ�p

	system("pause");
	return 0;
}
