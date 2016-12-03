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
	cout << "��ӡa1" << endl;
	a1.printArr();
	printf("\n");

	Array a2(20);
	Array a3(10);
	a3 = a1;
	cout << "��ӡa3" << endl;
	a3.printArr();
	printf("\n");

	if (a1 == a3)
	{
		printf("a1��a3���\n");
	}

	if (a2 != a3)
	{
		printf("a2��a3�����\n");
	}
	Array a4;
	a4 = a2 = a3;
	cout << "��ӡa4" << endl;
	a4.printArr();

	cout << a4;
	cin >> a4;

	cout << a4;
	system("pause");

	return 0;
}