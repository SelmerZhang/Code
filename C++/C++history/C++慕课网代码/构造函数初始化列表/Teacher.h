#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class Teacher
{
public:
	Teacher(string name="Jim",int age=20);
	void setName(string _name);//����
	string getName();
	void setGender(string _gender);//�Ա�
	string getGender();
	void setAge(int _age);//����
	int getAge();
	void teach();
private:
	string m_strName;
	int m_iAge;
	string m_strGender;
};