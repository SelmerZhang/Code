#ifndef MATRIX_H_
#define MATRIX_H_
#include<vector>

class matrix
{
public:
	matrix();
	matrix(int l, int w);
	matrix operator+(matrix &m1);
	void putmatrix();//�������
	~matrix();
private:
	
	int length;
	int width;
	vector <vector<int>> arr;
};

#endif

