#include "SList.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

void PrintSList(PNode* pHead)
{
	PNode pNext = NULL;
	assert(pHead);
	if (NULL == *pHead)
		return;
	
	pNext = *pHead;

	while (pNext)
	{
		printf("%d——> ", pNext->_data);
		pNext = pNext->_pNext;
	}

	
	printf("NULL\n");

}

PNode BuySListNode(DataType data)
{
	PNode NewNode = NULL;
	NewNode = (Node *)malloc(sizeof(Node));

	if (NULL == NewNode)
	{
		assert(NewNode);
		return NULL;
	}
	NewNode->_data = data;

	return NewNode;
}

void SListInit(PNode* pHead)
{
	assert(pHead);
	if (NULL == pHead)
		return;

	(*pHead)= NULL;
}

void SListPushBack(PNode* pHead, DataType data)
{
	PNode Tail = NULL;
	assert(pHead);

	Tail = *pHead;
	if (NULL == Tail)
	{
		Tail = (Node *)malloc(sizeof(Node));
		Tail->_data = data;
		Tail->_pNext = NULL;
		
		*pHead = Tail;
		return;
	}
	
	while (Tail->_pNext)
	{
		Tail = Tail->_pNext;
	}

	Tail->_pNext = (Node *)malloc(sizeof(Node));
	(Tail->_pNext)->_data = data;
	(Tail->_pNext)->_pNext = NULL;


}

void SListPopBack(PNode* pHead)
{
	PNode pNext = NULL;
	assert(pHead);

	if (NULL == *pHead)
		return;

	pNext = *pHead;

	if (NULL == pNext->_pNext)
	{
		free(pNext);
		*pHead = NULL;
		return;
	}

	while (pNext->_pNext && pNext->_pNext->_pNext)
	{
		pNext = pNext->_pNext;
	}

	free(pNext->_pNext);
	pNext->_pNext = NULL;
}

void SListPushFront(PNode* pHead, DataType data)
{
	PNode NewNode = NULL;
	assert(pHead);
	//空链表
	if (NULL == *pHead)
	{
		NewNode = BuySListNode(data);
		NewNode->_pNext = NULL;
	}
	//多个节点

	NewNode = BuySListNode(data);
	NewNode->_pNext = *pHead;
	*pHead = NewNode;

}

void SListPopFront(PNode* pHead)
{
	PNode Top = NULL;
	assert(pHead);
	//空链表
	if (NULL == *pHead)
		return;

	Top = *pHead;
	//一个节点
	if (NULL == Top->_pNext)
	{
		free(Top);
		Top = NULL;
		*pHead = Top;
		return;
	}
	//多个节点
	*pHead = Top->_pNext;
	free(Top);
}

PNode SListFind(PNode pHead, DataType data)
{
	PNode pCur = NULL;
	pCur = pHead;
	int count = 0;
	//空链表
	if (NULL == pCur)
		return NULL;
	//非空
	while (pCur)
	{
		if (data == pCur->_data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}

	return NULL;
	
}

void SListInsert(PNode* pHead, int pos, DataType data)
{
	PNode pCur = NULL;
	PNode NewNode = NULL;
	int count = 0;
	assert(pHead);
	//空链表
	if (NULL == *pHead)
		return;

	pCur = *pHead;
	while (pCur)
	{
		++count;
		if (pos == count)
		{
			NewNode = BuySListNode(data);
			NewNode->_pNext = pCur->_pNext;
			pCur->_pNext = NewNode;
			return;
		}
		pCur = pCur->_pNext;
	}

	return;
}

void SListErase(PNode* pHead, int pos)
{
	PNode pCur = NULL;
	PNode pFront = NULL;
	int count = 0;
	assert(pHead);
	if (NULL == pHead)
		return;

	pCur = *pHead;
	while (pCur)
	{
		++count;
		
		if (count == pos)
		{
			if (1 == count)//头
			{
				*pHead = pCur->_pNext;
				free(pCur);
				return;
			}
			else if (NULL == pCur->_pNext)//尾
			{
				pFront->_pNext = NULL;
				free(pCur);
				return;
			}
			else
			{
				pFront->_pNext = pCur->_pNext;
				free(pCur);
				return;
			}
		}
		pFront = pCur;
		pCur = pCur->_pNext;
	}
	return;
}

void SListDestroy(PNode* pHead)
{
	PNode pNext = NULL;
	assert(pHead);
	//空链表
	if (NULL == *pHead)
		return;

	//一个结点、多个结点
	while (*pHead)
	{
		pNext = (*pHead)->_pNext;
		free((*pHead));
		*pHead = pNext;
	}
}

int SListSize(PNode pHead)
{
	PNode pCur = NULL;
	int count = 0;
	if (NULL == pHead)
		return 0;
	
	pCur = pHead;
	while (pCur)
	{
		++count;
		pCur = pCur->_pNext;
	}
	return count;
}

void SListClear(PNode* pHead)
{
	PNode pFront = NULL;
	PNode pCur = NULL;
	assert(pHead);
	//空链表
	if (NULL == *pHead)
		return;

	pCur = (*pHead)->_pNext;
	//多个结点
	while (pCur)
	{
		pFront = pCur;
		pCur = pCur->_pNext;
		free(pFront);
	}
	(*pHead)->_pNext = NULL;
}

//PNode BuySListNode(DataType data)
//{
//}

PNode SListBack(PNode pHead)
{
	PNode pCur = NULL;
	if (NULL == pHead)
		return NULL;

	pCur = pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	return pCur;
}
