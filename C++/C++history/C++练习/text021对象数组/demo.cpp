#include<iostream>
#include<stdlib.h>
#include"Coordinate.h"
using namespace std;

int main(void)
{
    Coordinate coor[3];//��ջ�ж�������Coordinate
	coor[0].m_ix=3;
	coor[0].m_iy=2;//�������ݳ�Ա
	
    Coordinate *p=new Coordinate[3];//���������ڴ��
	p->m_ix=5;//p�󲻼ӷ�����[]��������p������λ�ü�p[0]��ͬ��p[0].m_xi=5
	p[0].m_iy=7;
	
	//���꣨1,1��
	p++;//p=p+1
	p->m_ix=11;
	p[0].m_iy=13;

p[1].m_ix=15;
p++;
p->m_iy=18;
	
	for(int i=0;i<3;i++)
	{
		cout<<"coor_x   "<<coor[i].m_ix<<endl;
		cout<<"coor_y   "<<coor[i].m_iy<<endl;
	}

	for(int j=0;j<3;j++)
	{
		cout<<"p_x   "<<p->m_ix<<endl;
		cout<<"p_y   "<<p->m_iy<<endl;
		p--;//p�ѽ�����������λ�ã�����Ҫ�����������
	}

    p++;//��pָ�س�ʼλ�ã����ͷ�p���ڴ�
	delete []p;
	p=NULL;
	
	system("pause");
	return 0;
}