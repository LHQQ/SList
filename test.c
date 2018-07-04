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
