#include<iostream>
using namespace std;

class Time
{
public:
private:
};

int main()
{
	int *p=new int(20);//ֱ�ӽ�20 ��ֵ��P��Ҳ���Ժ����ٸ�ֵ����*P=20
	if(p==NULL)
	{
	   system("pause");
	   return 0;
	}
	cout<<*p<<endl;
	delete p;
	p=NULL;


	int *q=new int[10];//�������һ����ʮ��������������ռ�
	if(q==NULL)
	{
	   system("pause");
	   return 0;
	}
	q[0]=1;
	q[1]=3;
	cout<<q[0]<<","<<q[1]<<endl;
	delete []q;//���ͷ������ָ���ʱ��delete��Ҫ�ӡ�[]�������ſ����ͷŵ��������������ռ䣬���û�о�ֻ���ͷŵ���һ��
	q=NULL;
	system("pause");
	return 0;
}
