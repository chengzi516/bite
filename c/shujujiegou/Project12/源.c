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

int main() {
	ln* plist=NULL;
	listpushback(&plist, 1);
	listpushback(&plist, 2);
	listpushback(&plist, 3);
	listpushback(&plist, 4);
	print(plist);

}