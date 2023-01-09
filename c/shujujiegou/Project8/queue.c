#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void queueinit(queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void queuepush(queue* pq, datatype x)
{
	assert(pq);
	qnode* newnode = (qnode*)malloc(sizeof(qnode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void queuepop(queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->tail = pq->head = NULL;

	}
	qnode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
}
bool queueempty(queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
datatype queuefront(queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;

}
datatype queueback(queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;

}
int queuesize(queue* pq)
{
	assert(pq);
	int size = 0;
	qnode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}