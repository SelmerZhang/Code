#include<iostream>
using namespace std;
int time=0;//ȫ�ֱ���������ᶯ����
//��N��Բ�̴�X���ᵽZ��
void move(int n,char x,char z)
{
	cout<<"��"<<++time<<"������"<<n<<"���̴�"<<x<<"�Ƶ�"<<z<<endl;
}
//��x����ֱ�����϶��´�С�ŵ����Ŵ�x���ᵽz����y����Ϊ���� 
void hanoi(int n,char x,char y,int z)
{
	if (n==1)
		move(1,x,z);//�����Ϊһ��Բ�̴�x�Ƶ�y
	else
	{
		hanoi(n-1,x,y,z);//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��Ϊ����
		move(n,x,y);//�����Ϊn��Բ�̴�x�Ƶ�z
		hanoi(n-1,y,x,z);//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x��Ϊ����
	}
}
int main()
{
	int n;
	cout<<"3����Ϊa,b,cԲ�������a���ϣ�������Բ������";
	cin>>n;
	hanoi(n,'a','b','c');
	system("pause");
	return 0;
}

