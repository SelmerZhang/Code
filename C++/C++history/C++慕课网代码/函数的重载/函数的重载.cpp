#include<iostream>
using namespace std;

void fun(int i=30,int j=20,int k=10);//����������
void fun(double i,double j);

int main()
{
	fun();
	fun(100);
	fun(100,200);
	fun(100,200,300);
	fun(1.1,2.2);//������Զ�ѡ���ܳɹ����õĺ���
	fun(1,2);
	system("pause");
	return 0;
}
 
void  fun(int i,int j,int k)
{
	cout<<i<<","<<j<<","<<k<<endl;
}

void fun(double i,double j)
{
	cout<<i<<","<<j<<endl;
}

