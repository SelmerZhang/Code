#include<iostream>//��Ԫ�������Կ�Ҳ������ĳ�Ա�����������س�Ա�������ǿ�������������ķ���һ��
using namespace std;

class Time
{
public:
	Time(int,int,int);
	friend void display(Time&);//����displayΪ��Ԫ����
private:
	int hour;
	int minute;
	int sec;
};

Time::Time(int h,int m,int s)
{
	hour=h;
	minute=m;
	sec=s;
}

void display(Time&t)
{
    cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}
int main()
{
	Time t1(12,45,37);
	display(t1);
	system("pause") ;
	return 0;
}
