#include "myArray.h"
#include <iostream>

Array::Array(int length)
{
	if (length < 0)
	{
		mLength = 0;
		mSpace = new int[mLength];
	}
	mLength = length;
	mSpace = new int[mLength];
}

/*
Array::Array(const Array& obj)
{
	this->mLength = obj.mLength;
	this->mSpace = new int[mLength];  //再次分配内存空间
	for (int i = 0; i != mLength; ++i)     //这里要进行赋值   之前没有这步，析构对象a2时报错
	{
		this->mSpace[i] = obj.mSpace[i];
	}
}*/

int Array::length()
{
	return mLength;
}
//a1.setData(i, i)
void Array::setData(int index, int value)
{
	*(mSpace + index) = value;
}
//a1.getData(i)
int Array::getData(int index)
{
	return *(mSpace + index);
}

void Array::printArr()
{
	for (int i = 0; i != this->mLength; ++i)
	{
		printf("%d ", this->mSpace[i]);
	}
}

Array::~Array()
{
	if (mSpace != NULL)
	{
		delete[] Array::mSpace;
	}
	std::cout << "Array被析构了" << std::endl;
}

//重载[]操作符 Array& operator [](Array &a); a[i] = i;
int& Array::operator [](int index) //函数返回值需要返回一个引用！！！！！！！
{
	return *(this->mSpace + index);
}

Array& Array::operator = (Array& a)
{
	//要释放原来的内存！！！！！
	if (this->mSpace != NULL)
	{
		delete []mSpace;
		this->mLength = 0;
	}
	this->mLength = a.mLength;
	this->mSpace = new int[mLength];
	for (int i = 0; i != mLength; ++i)
	{
		this->mSpace[i] = a[i];
	}
	return *this;
}

bool Array::operator==(Array& a)
{
	if (this->mLength == a.mLength)
	{
		for (int i = 0; i != this->mLength; ++i)
		{
			if (this->mSpace[i] != a.mSpace[i])
			{
				return false;
			}
		}
		return true;
	}

	return false;
}

bool Array::operator!=(Array& a)
{
	if (this->mLength != a.mLength) return true;
	for (int i = 0; i != this->mLength; ++i)
	{
		if (this->mSpace[i] != a.mSpace[i])
		{
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, Array& a)
{
	for (int i = 0; i != a.mLength; ++i)
	{
		os << a[i] << " ";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Array &a)
{
	if (a.mSpace != NULL)
	{
		delete[]a.mSpace;
	}
	a.mSpace = new int[a.mLength];

	for (int i = 0; i != a.mLength; ++i)
	{
		is >> a[i];
	}
	return is;
}
