#include<iostream>
#include<string>

using namespace std;

class Teacher
{
public:
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

void Teacher::setName(string _name)//����
{
	m_strName=_name;
}
string Teacher::getName()
{
	return m_strName;
}
void Teacher::setGender(string _gender)//�Ա�
{
	m_strGender=_gender;
}
string Teacher::getGender()
{
	return m_strGender;
}
void Teacher::setAge(int _age)//����
{
	m_iAge=_age;
}
int Teacher::getAge()
{
	return m_iAge;
}
void Teacher::teach()
{
	cout<<"�����Ͽ�"<<endl;
}

int main()
{
	Teacher t;
	t.setName("�ҵ���");
	t.setGender("��");
	t.setAge(0);
	cout<<t.getName()<<"  "<<t.getGender()<<"  "<<t.getAge<<endl;
//	t.taech(); 
	system("pause");
	return 0;
}
