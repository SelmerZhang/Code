class Array
{
public:
	Array(int count);//Ĭ�Ϲ��캯��
	Array(const Array &arr);//�������캯��
	~Array();//��������
	void setCount(int count);
	int getCount();
	void printAddr();//��ӡָ��m_pArr��ֵ
private:
	int m_iCount;
	int *m_pArr;
};