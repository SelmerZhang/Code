#include<iostream>
#include"matrix.h"
using namespace std;

matrix::matrix()                                      //���幹�캯��
{
	mat[2][3] = { 0};
}

matrix matrix::operator+(matrix &b)                //���������������+������
{
	matrix c;
	for (int i = 0; i<2; i++)
		for (int j = 0; j<3; j++)
		{
		c.mat[i][j] = this->mat[i][j] + b.mat[i][j];
		}
	return c;
}

matrix operator-(matrix &a,matrix &b)                //���������������-������
{
	matrix c;
	for (int i = 0; i<2; i++)
	
		for (int j = 0; j<3; j++)
		{
		c.mat[i][j] = a.mat[i][j] - b.mat[i][j];
	
		}
	return c;
}



void matrix::input()                                   //�����������ݺ���
{
	cout << "input value of matrix:" << endl;
	for (int i = 0; i<2; i++)
		for (int j = 0; j<3; j++)
			mat[i][j]=rand()%100;
}

void matrix::display()                                //����������ݺ���
{
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<3; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}