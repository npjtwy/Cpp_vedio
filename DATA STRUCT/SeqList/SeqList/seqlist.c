#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"
#include <memory.h>


typedef struct __tag_SeqList
{
	int length;
	int capacity;
	unsigned int *node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	TSeqList *tmp = NULL;
	int ret = 0;
	
	//分配内存并初始化
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err:%d", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));

	tmp->node = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func SeqList_Create() err: malloc err %d\n", ret);
		return NULL;
	}

	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;
}

void SeqList_Destroy(SeqList* list)
{
	if (list == NULL)
	{
		printf("NULL\n");
		return;
	}
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (tlist->node != NULL)
	{
		free(tlist);		//直接销毁
	}

}

void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		printf("list is NULL\n");
	}

	tlist->length = 0;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		printf("list is NULL\n");
		return -1;
	}

	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		printf("list is NULL\n");
		return -1;
	}

	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList *tlist = (TSeqList*)list;
	int ret = 0;

	if (tlist == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert err: %d\n", ret);
		return ret;
	}

	//检查还有没有 空间插入
	if ( tlist->length == tlist->capacity)
	{
		ret = -2;
		printf("list is full\n");
		return ret;
	}

	//容错修正
	if (pos > tlist->length )
	{
		pos = tlist->length;
	}


	//插入
	for ( int i = tlist->length; i > pos; --i)
	{
		tlist->node[i] = tlist->node[i - 1];
	}

	tlist->node[pos] = (unsigned int)node;
	tlist->length++;

	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;

	if (tlist == NULL || pos < 0)
	{
		printf("SeqList_Get err\n");
		return NULL;
	}

	return (SeqListNode*)tlist->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;

	if (tlist == NULL || pos < 0)
	{
		printf("SeqList_Get err\n");
		return NULL;
	}

	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	SeqListNode *ret = (SeqListNode*)tlist->node[pos];
	int i = 0;
	//删除
	for (i = pos +1; i < tlist->length; ++i)
	{
		tlist->node[i - 1] = tlist->node[i];
	}

	tlist->length--;
	return ret;
}