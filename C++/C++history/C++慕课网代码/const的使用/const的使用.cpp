#include<iostream>
using namespace std;

//void fun(const int &a,const int &b);//"&"�Ǳ�ʾ����,����Ĳ����Ǵ���ģ���Ϊ const���ܸ�������ֵ
void fun( int &a, int &b);

int main()
{
	int x=3;
	int y=5;
	fun(x,y);
	cout<<x<<","<<y<<endl;

	system("pause");
	return 0;
}

//void fun(const int &a,const int &b)
void fun( int &a, int &b)
{
	a=10;
	b=20;
}
