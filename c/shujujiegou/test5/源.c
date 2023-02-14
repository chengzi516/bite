#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��д���С����е��ص�����Ƚ��ȳ�����һ�ν��г��ӣ�����һ�˽�����ӡ�
//�����Ļ������Բ��ʺ�������������Ϊ�����ƶ�ͷ������ĺܶ����ݡ�
//���ڶ��ж��ԣ����ʺϵķ�����������
typedef struct queuenode {
	struct queuenode* next;
	int data;  //  ��������ʵ�������ġ�
}qnode;

typedef struct queue {
	qnode* head;
	qnode* tail; //Ҫ��ͷ��β����ʵ��һ�߳���һ�߽��Ĺ��ܡ�
}queue;

//���г�ʼ��
void queueinit(queue* q) {
	q->head = q->tail = NULL;
}
//Ҳ���Բ���������Ķ��������ṹ��ķ�������������������ṹ��Ͳ��ö���ָ���ˡ�


//��Ӳ���
void queuepull(queue* q,int x) {
	qnode* newp = (qnode*)malloc(sizeof(qnode));
	newp->data = x;
	//�ҵ���β���в��룬��������������Ҳ���Բ�ȡ�ڱ��ڵ�Ͳ��÷�����ˡ�
	if (q->tail == NULL){
		q->head = q->tail = newp;
	}
	else {
		q->tail->next = newp;
		q->tail = newp;
	}

}
//���Ӳ���
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
//ȡ��ͷ����
int getqueuedata(queue* q) {
	return q->head->data;
}


