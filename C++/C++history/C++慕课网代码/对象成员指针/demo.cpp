#include<iostream>
#include<stdlib.h>
#include"Line.h"

using namespace std;

/*  �����Աָ��
       
		 ����������
		     �����ࣺCoordinate   ���ݳ�Աm_iY��m_iX    �����캯�����������������ݷ�װ����
			 �߶��ࣺLine         ���ݳ�Ա��ָ��A��m_pCoorA����ָ��B��m_pCoorB��
*/


int main()
{
	Line *p=new Line(1,2,3,4);
	p->printInfo();
	delete p;

	cout<<sizeof(p)<<endl;
	cout<<sizeof(Line)<<endl;//line��������������ָ������ռ8���ڴ浥Ԫ
	system("pause");
	return 0;
}
