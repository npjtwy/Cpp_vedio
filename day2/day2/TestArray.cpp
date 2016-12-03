#include <iostream>
#include <string>
#include "myArray.h"
using  namespace std;

int main()
{
	Array a1(10);

	for (int i = 0; i != a1.length(); ++i)
	{
		a1[i] = i;
	}
	cout << "打印a1" << endl;
	a1.printArr();
	printf("\n");

	Array a2(20);
	Array a3(10);
	a3 = a1;
	cout << "打印a3" << endl;
	a3.printArr();
	printf("\n");

	if (a1 == a3)
	{
		printf("a1和a3相等\n");
	}

	if (a2 != a3)
	{
		printf("a2和a3不相等\n");
	}
	Array a4;
	a4 = a2 = a3;
	cout << "打印a4" << endl;
	a4.printArr();

	cout << a4;
	cin >> a4;

	cout << a4;
	system("pause");

	return 0;
}