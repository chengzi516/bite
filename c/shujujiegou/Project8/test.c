#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void testqueue()
{
	queue pq;
	queueinit(&pq);
	queuepush(&pq, 1);
	queuepush(&pq, 2);
	queuepush(&pq, 3);
	queuepush(&pq, 4);
	queuepush(&pq, 5);
	int a = queuesize(&pq);
	printf("%d ", a);
	while (!queueempty(&pq))
	{
		printf("%d ", queuefront(&pq));
		queuepop(&pq);
	}
	
}
int main()
{
	testqueue();
}