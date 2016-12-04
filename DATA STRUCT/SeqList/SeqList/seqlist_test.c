#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "seqlist.h"

typedef struct Teacher
{
	int age;
	char name[64];

}Teacher;

int main()
{
	int  ret = 0;
	SeqList *list = NULL;

	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	list = SeqList_Create(10);

	if (list == NULL)
	{
		printf("func SeqList_Create() err\n");
	}
	
	ret = SeqList_Insert(list, (SeqListNode*)&t1, 0);		//插入
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);		//插入
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);		//插入
	ret = SeqList_Insert(list, (SeqListNode*)&t4, 0);		//插入
	ret = SeqList_Insert(list, (SeqListNode*)&t5, 0);		//插入

	//遍历
	for (int i = 0; i < SeqList_Length(list); ++i)
	{
		Teacher* tmp = (Teacher*)SeqList_Get(list, i);

		printf("age: %d\n", tmp->age);
	}

	system("pause");
	return 0;
}