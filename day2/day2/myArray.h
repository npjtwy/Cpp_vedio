#ifndef _MYARRAY_H_
#define _MYARRAY_H_
#include <iostream>
class Array
{
private:
	int mLength;
	int* mSpace;

public:
	Array() { mLength = 10; mSpace = new int(mLength); }
	Array(int length);
	Array(const Array& obj);
	int length();
	void setData(int index, int value);
	int getData(int index);
	void printArr();
	~Array();
	//����������
	//[]������
	int& operator [](int index);
	//=������
	Array& operator =(Array& a);
	//==������
	bool operator==(Array& a);
	//!=������
	bool operator!=(Array& a);
	//<< �� >>�����ֻ������Ԫ��������ȫ�ֺ���ʵ������
	friend std::ostream& operator<<(std::ostream& os, Array &a);
	//>>
	friend std::istream& operator>>(std::istream& is, Array &a);

};

#endif
