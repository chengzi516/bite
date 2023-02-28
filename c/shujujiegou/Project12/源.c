#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int sltdatatype;
typedef struct listnode {
	sltdatatype x;
	struct listnode* next;
	//定义链表里单个节点的结构
}ln;

void print(ln* phead) {
	//assert在这里不需要，不过是打出来没有数据而已。
	while (phead) {
		printf("%d ,", phead->x);
		phead = phead->next;
	}
	printf("NULL\n");
}
//尾插
void listpushback(ln** phead, sltdatatype x) {
	if (*phead == NULL) {
		ln* new = (ln*)malloc(sizeof(ln));
		if (new == NULL) {
			perror("malloc fail");
			return;

		}
		new->next = NULL;
		new->x = x;
		*phead = new;  //这里改变了传入的plist指针的指向，所以需要传二级指针。
	}
	else {
		ln* tail = *phead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		ln* new = (ln*)malloc(sizeof(ln));
		if (new == NULL) {
			perror("malloc fail");
			return;

		}
		new->next = NULL;
		new->x = x;
		tail->next = new;
	}
}
//头插
void listpushhead(ln** phead, sltdatatype x) {
	ln* new = (ln*)malloc(sizeof(ln));
	new->x = x;
	if (*phead == NULL) {
		*phead = new;
	}
	else {
		new->next = (*phead);
		*phead = new;
	}
}
//尾删
void listpopback(ln** phead) {
	ln* tail = *phead;
	if (*phead == NULL) {
		printf("链表已经为空！\n");
		return;
	}
	else if ((*phead)->next == NULL) {
		free(*phead);
		*phead = NULL;
	}
	else {
		while (tail->next->next != NULL) {
			tail = tail->next;
		}
		tail->next = NULL;
		free(tail->next);
	}
}
//头删
void listpopfront(ln** phead) {
	if (*phead == NULL) {
		printf("链表已经为空!\n");
		return;
	}
	else {
		ln* p = (*phead)->next;
		free(*phead);
		*phead = p;
	}
}
//查找
ln* listfind(ln* phead,sltdatatype x) {
	ln* cur = phead;
	while (cur != NULL) {
		if (cur->x == x) {
			return cur;
		}
		cur = cur->next;
	}
}
//插入在pos后
void listinsert(ln* pos, sltdatatype x) {
	ln* new = (ln*)malloc(sizeof(ln));
	new->x = x;
	new->next = pos->next;
	pos->next = new;
}
//销毁
void destroylist(ln** phead) { //要传二级指针，因为在print里plist并未被置为空。
	
	
	while (*phead)
	{
		ln*p = (*phead);
		*phead = (*phead)->next;
		free(p);
		
	}
}
int main() {
	ln* plist=NULL;
	listpushback(&plist, 1);
	listpushback(&plist, 2);
	listpushback(&plist, 3);
	listpushback(&plist, 4);
	listpushhead(&plist, 5);
	destroylist(&plist);
	print(plist);

}