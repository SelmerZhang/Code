#include<iostream>
#include<stdlib.h>
#include"Rect.h"
#include"Circle.h"
using namespace std;

/*��̬��̬���麯��
      Ҫ��
	       1������Shape�࣬��Ա������calcArea���������캯������������
		   2������Rect�࣬��Ա������caclArea���������캯������������
		                  ���ݳ�Ա��m_dWidth��m_dHeight
           3������Circle�� ��Ա����caclArea���������캯������������
		                   ���ݳ�Ա��m_dR
*/

int main()
{
	Shape *shape1=new Rect(3.6);
	Shape *shape2=new Circle(5);
	
	shape1->caleArea();
	shape2->caleArea();

	delete shape1;
	delete shape2;


	system("pause");
	return 0;
		 
}