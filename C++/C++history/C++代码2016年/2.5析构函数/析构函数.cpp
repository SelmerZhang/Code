#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(int n,string nam,char s)
	{
		num=n;
		name=nam;
		sex=s;
		cout<<"Constructor called"<<endl;
	}

	~Student()//��������
	{
		cout<<"Destructor called"<<endl;//ˢ��
	}

	void display()
	{
		cout<<"mun:"<<num<<endl<<"name:"<<name<<endl<<"sex"<<sex<<endl;
	}

private:
	int num;
	string name;
	char sex;

};


int main()
{
	Student stud1(10010,"wangli",'f');//��������ע���ַ��ĳ�ʼ����ʽ
	stud1.display();
	Student stud2(10020,"wangli",'m');//��������ע���ַ��ĳ�ʼ����ʽ
	stud2.display();
	system("pause");
    return 0; 
}