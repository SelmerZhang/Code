#include<iostream>
#include<string>
using namespace std;
int main()
{
	char word[5]="?ate";
	for (char ch='a';strcmp(word,"mate");ch++)//ch++��ASSCI���
	{
		cout<<word<<endl;
		word[0]=ch;//������һ����ĸ
	}
    cout<<"After loop ends,word is"<<word<<endl;
	system("pause");
	return 0;
}