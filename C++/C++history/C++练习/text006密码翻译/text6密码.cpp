#include<iostream>
using namespace std;
int main()
{
    char admin[100];
	int i;
	cout<<"������ԭ���룺";
	cin>>admin;
	for(i=0;admin[i]!='\0';i++)
	{
		admin[i]=admin[i]-4;
	}
	cout<<"������Ϊ��"<<admin<<'\n';
}