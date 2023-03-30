#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


//typedef struct BinaryTreeNode* QDatatype;
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDatatype data;
//}QNode;
//
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
//
//void QueuePush(Queue* pq, QDatatype x)
//{
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//
//
//	if (pq->head == NULL)
//	{
//		assert(pq->tail == NULL);
//
//
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//
//
//	pq->size++;
//}
//
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head != NULL);
//
//
//	/*QNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//
//
//	if (pq->head == NULL)
//		pq->tail = NULL;*/
//
//
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//
//
//	pq->size--;
//}
//
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//
//
//	return pq->size;
//}
//
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//
//	return pq->size == 0;
//}
//
//
//QDatatype QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//
//	return pq->head->data;
//}
//
//
//QDatatype QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//
//	return pq->tail->data;
//}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);


BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}


	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;


	return node;
}


void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL)
		return;
	printf("%d->", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);


}


void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%d->", root->_data);
	BinaryTreeInOrder(root->_right);
}


void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%d->", root->_data);
}
void BinaryTreeDestory(BTNode** root) {
	assert(root);
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;

}
int BinaryTreeSize(BTNode* root) {
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}


int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;


	return  BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);


}
BTNode* CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);




	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;
	node3->_right = node7;




	return node1;
}


int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)
		return;
	if (root->_data == x)
		return root;
	BTNode* l = BinaryTreeFind(root->_left, x);
	if (l)
		return l;
	BTNode* r = BinaryTreeFind(root->_right, x);
	if (r)
		return r;
	return NULL;
}
void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q)) {
		BTNode* new = QueueFront(&q);
		QueuePop(&q);
		printf("%d->", new->_data);
		if (new->_left)
			QueuePush(&q, root->_left);
		if (new->_right)
			QueuePush(&q, root->_right);
	}
	QueueDestroy(&q);


}
//int BinaryTreeComplete(BTNode* root) {
//
//
//}
int main()
{
	BTNode* p = CreatTree();
	//printf("%d", BinaryTreeLeafSize(p));
	//printf("%d", BinaryTreeLevelKSize(p, 4));
	BinaryTreeLevelOrder(p);
}




﻿