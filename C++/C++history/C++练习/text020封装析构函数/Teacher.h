#include<iostream>
#include<string>
using namespace std;
class Teacher
{
public:
	Teacher(string name ="Jim",int age=10);
	Teacher(const Teacher&tea);//�������캯��
	~Teacher();
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();

private:
	string m_strName;
	int m_iAge;
};