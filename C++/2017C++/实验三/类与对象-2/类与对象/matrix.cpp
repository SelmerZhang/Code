#include<iostream>
#include"matrix.h"
using namespace std;

matrix::matrix()//�޲ι��캯��
{
   num = new int[length*width];
   num = { 0 };
}

matrix::matrix(int l, int w, int *n[])//���ع��캯��
{
	int i;
	length = l;
	width = w;
	num = new int[length][width];
	int *p = num;
	for (i = 0; i<length*width; i++)
	{
		*p++ = *n++;
	}
}

matrix matrix::operator+(matrix &m1)
{
	matrix m2;
	for (int i = 0; i < length*width; i++)
		{
		m2.num[i] = num[i] + m1.num[i];
		}
	return m2;
}

void matrix::putmatrix()//�������
{
	for (int i = 0; i<length*width; i++)
	{
		cout << num[i] << "  ";
		if ((i + 1)%width == 0)
			cout << endl;
	}
}

matrix::~matrix()
{
	delete[]num;
}