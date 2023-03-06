#define _CRT_SECURE_NO_WARNINGS 1
// SeqList.c
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);

	for (inti = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}

	printf("%\n");
}

void CheckCacpity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		ps->capacity = newcapacity;
	}
}

// ���¼����ӿ��Ƚ�������Insert��Erase��ʵ�֣�����ٽ�����ʵ��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	//assert(ps);
	//CheckCacpity(ps);

	//ps->a[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);

	/*CheckCacpity(ps);

	int end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}

	ps->a[0] = x;
	++ps->size;*/

	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	//int start = 0;
	//while (start < ps->size-1)
	//{
	//	ps->a[start] = ps->a[start + 1];
	//	++start;
	//}
	//int? start = 1;
	//while (start < ps->size)
	//{
	//	ps->a[start-1] = ps->a[start];
	//	++start;
	//}

	//--ps->size;
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	//ps->size--;
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);

	CheckCacpity(ps);

	//int end = ps->size - 1;
	//while (end >= pos)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}

	int end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}


	ps->a[pos] = x;
	ps->size++;
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps && pos < ps->size);

	//int start = pos;
	//while (start < ps->size-1)
	//{
	//	ps->a[start] = ps->a[start + 1];
	//	++start;
	//}

	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}

	ps->size--;
}
