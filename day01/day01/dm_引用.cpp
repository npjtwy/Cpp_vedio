#include "iostream"
using namespace std;

int geta1()
{
	int a;
	a = 15;
	return a;
}

int & geta2()
{
	int a;
	a = 20;
	return a;
}

int * geta3()
{
	int a;
	a = 30;
	return &a;
}
void main()
{
	
	int a = 10;
	int a1 = geta1();
	int a2 = geta2();
	int &a3 = geta2();
	int p3 = a3;
	printf("a1: %d\na2: %d\na3: %d\n", a1, a2, a3);
	
	
	
	cout << "abc..." << endl;
	system("pause");
}