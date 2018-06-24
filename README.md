# SList
//SList.h

#ifndef __SLIST_H__
#define __SLIST_H__

#pragma once

typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;

}Node, *PNode;


void SListInit(PNode* pHead);//链表初始化
void SListPushBack(PNode* pHead, DataType data);//尾插
void SListPopBack(PNode* pHead);//尾删
void SListPushFront(PNode* pHead, DataType data); //头插
void SListPopFront(PNode* pHead);//头删
void SListInsert(PNode* pHead, int pos, DataType data);// 在链表pos位置后插入结点data  
void SListErase(PNode* pHead, int pos);// 删除链表pos位置上的结点    问题 为什么int pos 处传的 PNode pos
void SListDestroy(PNode* pHead);// 销毁单链表
void SListClear(PNode* pHead);// 将链表中的结点清空 （保留头结点）

// 查找值为data的结点，返回该结点在链表中的位置 
PNode SListFind(PNode pHead, DataType data);
// 求链表中结点的个数 
int SListSize(PNode pHead);
// 获取结点 
PNode BuySListNode(DataType data);
// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead);



#endif //__SLIST_H__

//SList.c

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

//test.c
#include "SeqListD.h"

void TestSeqListDInit()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDInit(NULL);
}

void TestCheckCapacity()
{
	SeqListD s;
	SeqListDInit(&s);
	CheckCapacity(&s);
	CheckCapacity(NULL);

}
void TestSeqListDSize()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);

	printf("%d\n", SeqListDSize(NULL));

	printf("%d\n",SeqListDSize(&s));
}
void TestSeqListDPushBack()
{
	SeqListD s;
	SeqListDInit(&s);

	SeqListDPushBack(NULL, 1);

	SeqListDPushBack(&s, 1);
	PrintSeqListD(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	SeqListDPushBack(&s, 6);
	SeqListDPushBack(&s, 7);
	SeqListDPushBack(&s, 8);
	SeqListDPushBack(&s, 9);
	SeqListDPushBack(&s, 0);
	PrintSeqListD(&s);

	SeqListDPushBack(&s, 1);
	PrintSeqListD(&s);

}

void TestSeqListDClear()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	SeqListDPushBack(&s, 6);
	printf("%d\n", SeqListDSize(&s));

	SeqListDClear(NULL);
	SeqListDClear(&s);
	printf("%d\n", SeqListDSize(&s));

}

void TestSeqListDDestroy()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	SeqListDPushBack(&s, 6);
	SeqListDDestroy(&s);
}
int main()
{
	//TestSeqListDInit();
	//TestCheckCapacity();
	//TestSeqListDSize();
	//TestSeqListDPushBack();
	//TestSeqListDClear();
	TestSeqListDDestroy();
	return 0;
}
