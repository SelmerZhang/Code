#include<iostream>
using namespace std;
int main()
{
	char animal[20]="bear";
	const char*bird="wren";
	char*ps;

	cout<<animal<<" and "<<bird<<endl;

	cout<<"Enter a kind of animal:"<<endl;
    cin>>animal;

	ps=animal;
	cout<<ps<<endl;

	cout<<animal<<" at "<<(int *)animal<<endl;
	cout<<ps<<" at "<<(int*)ps<<endl;
	//animal��psָ��ͬһ���ڴ棬������������ֵ�͵�ַ��һ����

	system("pause");
	return 0;
}