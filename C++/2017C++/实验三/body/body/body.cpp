#include<iostream>
#include<string>
#include"body.h"
using namespace std;

body::body()
{
	Strname = "luck";

}

body::body(char name, int height, int weight)
{
	Strname = name;
	Iheight = height;
	Iweight = weight;
}

void body::getbody()
{
	cout << "please input the name" << endl;
	cin >> Strname;
	cout << "please input the height" << endl;
	cin >> Iheight;
	cout << "please input the weight" << endl;
	cin >> Iweight;
}

void cheakbody(body&a)
{
	if (((a.Iheight - 110) * 1.3 < a.Iweight)&&((a.Iheight - 110) * 0.9> a.Iweight))
	{
		cout << a.Strname << "���ش�꣬���彡��" << endl;
	}
	else
		cout<<a.Strname << "���ز���꣬���岻����" << endl;
	getchar();
}


