#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//书写双向链表，此链表为带头双向循环链表。
typedef int datatype;
typedef struct snode {
	datatype data;
	struct snode* prev;
	struct snode* next; // 实现双向就需要两个指针，分别指向前面和后面。
}snode;

//对链表进行初始化。
snode* nodeinit() { //也可采取二级指针传参方式。
	// 哨兵节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。
	snode* soilder = (snode*)malloc(sizeof(snode));
	soilder->next = soilder;
	soilder->prev = soilder;
	soilder->data = 0; //将两个指针都先指向自己，其奇妙的地方后面会展示。
	return soilder;
}
//尾插法
void nodepushback(snode* phead,datatype x) {//当引用了头节点，就不会存在if NULL，phead=newp的情况，也就是不会去改变phead本身，而是直接进行链接。
	 //找到尾tail。
	snode* tail = phead->prev; //双向的好处就在这里。
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	tail->next = newp;
	newp->next = phead;
	newp->prev = tail;
	phead->prev = newp;
}
//打印函数
void print(snode* phead) {
	snode* newp = phead->next;
	while (newp != phead) {
		printf("%d ", newp->data);
		newp = newp->next;
	}

}
//头插法
void nodepushfront(snode* phead,datatype x) {
	//直接在phead后面插
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->prev = phead;
	newp->data = x;
	newp->next = phead->next;
	phead->next->prev = newp;
	phead->next = newp;  //也可以先将第一个节点保存起来，这样更简单易懂。
}
//头删法
void nodepopfront(snode* phead) {
	//注意只剩phead就别删了。
	assert(phead->next != phead);
	snode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
}
//尾删法
void nodepopback(snode* phead) {
	assert(phead->next != phead);
	snode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
}
//插入
void nodeinsert(snode* pos, datatype x) {
	assert(pos);
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	newp->next = pos;
	newp->prev = pos->prev;
	pos->prev->next = newp;
	pos->prev = newp;
}
//删除
void nodedelete(snode* pos) {
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//有了删除与操作，就可以以代码复用的形式，重写头删尾删头插尾插四种操作。
// 尾删： nodedelete(phead->prev);
int main() {
	snode* phead = nodeinit();
	nodepushback(phead, 1);
	nodepushback(phead, 2);
	nodepushback(phead, 3);
	nodepushback(phead, 4);
	nodepushfront(phead, 5);
	//nodepopfront(phead);
	nodeinsert(phead->next->next->next, 10);
	nodedelete(phead->next->next->next);
	//尾删的重写
	nodedelete(phead->prev);
	//头删
	nodedelete(phead->next);
	//头插
	nodeinsert(phead->next, 100);
	//尾插
	nodeinsert(phead, 1000);



	print(phead);
}