#ifndef MATRIX_H_
#define MATRIX_H_


class matrix                                          //����matrix��
{
public:
	matrix();                                          //Ĭ�Ϲ��캯��
	matrix operator+(matrix &);        //�����������+��
	friend matrix operator-( matrix &,matrix &);
	void input();                                      //�������ݺ���
	void display();                                    //������ݺ���
private:
	int mat[2][3];
};

#endif

