#include<iostream>
using namespace std;

template<class numtype>//������ģ�壬����������numtype

class Compare//��ģ����comepare
{
public:
	Compare(numtype a,numtype b)//���幹�캯��
	{
		x=a;
		y=b;
	}
	numtype max()
	{
		return(x>y)?x:y;
	}
	numtype min()
	{
		return(x<y)?x:y;
	}
private:
	numtype x,y;
};

int main()
{
	Com pare<int>cmp1(3,7);
	cout<<cmp1.max()<<"is the Maximum of two integer number"<<endl;
    cout<<cmp1.min()<<"is the Minimum of two integer number"<<endl;
	system("pause");
	return 0;
}
