#include<iostream>
#include<stdlib.h>
#include"Coordinate.h"
using namespace std;

/*
   Ҫ��
       ����Coordinate��
	   ���ݳ�Աm_ix��m_iy
	   ��������ָ�룬��ͨ��ָ��ٿض���
	   ����������ĺᡢ������ĺ�

 */
int main()
{
	Coordinate *p1=NULL;
	p1=new Coordinate;
	Coordinate *p2=new Coordinate();//�����������Ƚϸ�ֵ�Ľ��һ�������ſ��п���
	p1->m_iX=10;
	p1->m_iY=20;

	(*p2).m_iX=30;
	(*p2).m_iY=40;
/*���ֲ�ͬ���͵ĸ�ֵ��ʽ*/

	cout<<(p1->m_iX+(*p2).m_iX)<<endl;
	
	cout<p1->m_iY+(*p2).m_iY<<endl

	system("pause");
	return 0;
}