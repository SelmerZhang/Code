#include<iostream>
#include<stdlib.h>
#include"Array.h"

using namespace std;

/*Array��
    ���ݳ�Ա��m_iLen��ʾ���鳤��
	��Ա����
	   ���캯��
	   ��������
	   len�ķ�װ����
	   ��Ϣ�������printinfo
*/



int main()
{
	Array arr1(10);
	arr1.printInfo().setLen(5);/*
							   ���ȴ�ӡʵ����������Ĳ���10��Ȼ�󷵻�һ��ָ��arr1���ָ�룬
	                           �����ǡ�.setLen(5)��,�������еķ�װ����������Ĳ��������˱仯��Ϊ��5��
	                           ����ӡ������len��ֵ
	                           */
	cout<<arr1.getLen()<<endl;
	system("pause");
	return 0;
}