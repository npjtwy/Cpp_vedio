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
	//操作符重载
	//[]操作符
	int& operator [](int index);
	//=操作符
	Array& operator =(Array& a);
	//==操作符
	bool operator==(Array& a);
	//!=操作符
	bool operator!=(Array& a);
	//<< 和 >>运算符只能以友元函数或者全局函数实现重载
	friend std::ostream& operator<<(std::ostream& os, Array &a);
	//>>
	friend std::istream& operator>>(std::istream& is, Array &a);

};

#endif
