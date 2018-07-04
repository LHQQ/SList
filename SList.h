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
