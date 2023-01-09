#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int datatype;
typedef struct queuenode
{
	struct queuenode* next;
	datatype data;
}qnode;

typedef struct queue
{
	qnode* head;
	qnode* tail;
}queue;

void queueinit(queue* pq);
void queuepush(queue* pq, datatype x);
void queuepop(queue* pq);
bool queueempty(queue* pq);
datatype queuefront(queue* pq);
datatype queueback(queue* pq);
int queuesize(queue* pq);

