#include<iostream>
using namespace std;
int main()
{
	int max(int a,int b,int c=0);//��Ĭ�ϲ���
	int a,b,c;
	cout<<"please enter three numbers";
	cin>>a>>b>>c;
	//���������ʽ�Ľ����һ��
	cout<<"max(a,b,c)"<<max(a,b,c)<<endl;
	cout<<"max(a,b,c)"<<max(a,b)<<endl;
	return 0;
}
int max(int a,int b,int c)
{
	if(a<b)
		a=b;
	if(a<c)
		a=c;
	return a;
}
