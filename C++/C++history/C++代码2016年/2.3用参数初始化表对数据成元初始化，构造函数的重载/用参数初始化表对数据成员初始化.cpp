#include<iostream>
using namespace std;

class Box
{
public:
	Box();//����һ���޲εĹ��캯��
	Box(int h,int w,int l):height(h),width(w),length(l){}//����һ���вεĹ��캯�����ò����ĳ�ʼ��������ݳ�Ա���г�ʼ��
	int volume();
private:
	int height;
	int width;
	int length;
};

Box::Box()
{
	height=10;
	width=10;
	length=10;
}

int Box::volume()
{
	return (height*width*length);
}

int main()
{
	Box box1;//û�в���
	cout<<"the volume of box1 is"<<box1.volume()<<endl;
	Box box4(15,30,20);
	cout<<"the volume of box1 is"<<box4.volume()<<endl;
	system("pause");
	return 0; 




}