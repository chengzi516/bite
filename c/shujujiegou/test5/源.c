#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//书写队列。队列的特点就是先进先出，在一段进行出队，在另一端进行入队。
//这样的话很明显不适合数组来做，因为数组移动头部会更改很多数据。
//对于队列而言，最适合的方法就是链表。
typedef struct queuenode {
	struct queuenode* next;
	int data;  //  单链表来实现是最方便的。
}qnode;

typedef struct queue {
	qnode* head;
	qnode* tail; //要有头有尾才能实现一边出和一边进的功能。
}queue;

//进行初始化
void queueinit(queue* q) {
	q->head = q->tail = NULL;
}
//也可以不采用上面的定义两个结构体的方法，在这里采用两个结构体就不用二级指针了。


//入队操作
void queuepull(queue* q,int x) {
	qnode* newp = (qnode*)malloc(sizeof(qnode));
	newp->data = x;
	//找到队尾进行插入，这里分两种情况，也可以采取哨兵节点就不用分情况了。
	if (q->tail == NULL){
		q->head = q->tail = newp;
	}
	else {
		q->tail->next = newp;
		q->tail = newp;
	}

}
//出队操作
void queuepop(queue* q) {
	if (q->head->next = NULL) {
		free(q->head);
		q->head = q->tail = NULL;
	}
	else {
		qnode* newp = q->head->next;
		free(q->head);
		q->head = newp;
	}
}
//取队头数据
int getqueuedata(queue* q) {
	return q->head->data;
}


