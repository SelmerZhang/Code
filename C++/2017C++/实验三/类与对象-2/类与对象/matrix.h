#ifndef MATRIX_H_
#define MATRIX_H_

class matrix
{
public:
	matrix();
	matrix(int l, int w, int *n[]);
	matrix operator+(matrix &m1);
	void putmatrix();//�������
	~matrix();
private:
	int *num;
	int length;
	int width;
};

#endif

