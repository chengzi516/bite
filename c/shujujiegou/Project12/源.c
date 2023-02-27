#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int sltdatatype;
typedef struct listnode {
	sltdatatype x;
	struct listnode* next;
	//���������ﵥ���ڵ�Ľṹ
}ln;

void print(ln* phead) {
	//assert�����ﲻ��Ҫ�������Ǵ����û�����ݶ��ѡ�
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
		*phead = new;  //����ı��˴����plistָ���ָ��������Ҫ������ָ�롣
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