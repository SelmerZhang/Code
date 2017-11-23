#include<iostream>
using namespace std; 
class Date;
class Time
{
public:
	Time(int ,int,int);
	void display(Date &);
private:
	int hour;
	int minute;
	int sec;
};

class Date
{
public:
	Date(int,int,int);
	friend void Time::display(Date&);//����Time�е�display����Ϊ�������Ԫ������Ա
private:
	int month;
	int day;
	int year;
};

Time::Time(int h,int m,int s)
{
	hour=h;
	minute=m;
	sec=s;
}

void Time::display(Date &d)
{
	cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
	cout<<hour<<":"<<minute<<":"<<sec<<endl;//���ñ�������е�˽�г�Ա
}

Date::Date(int m,int d,int y)
{
	month=m;
	day=d;
    year=y;
}
int main()
{
	Time t1(10,13,24);
	Date d1(12,25,2007);
	t1.display(d1);
	system("pause");
	return 0;
}
