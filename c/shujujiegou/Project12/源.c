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
//β��
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
//ͷ��
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
//βɾ
void listpopback(ln** phead) {
	ln* tail = *phead;
	if (*phead == NULL) {
		printf("�����Ѿ�Ϊ�գ�\n");
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
//ͷɾ
void listpopfront(ln** phead) {
	if (*phead == NULL) {
		printf("�����Ѿ�Ϊ��!\n");
		return;
	}
	else {
		ln* p = (*phead)->next;
		free(*phead);
		*phead = p;
	}
}
//����
ln* listfind(ln* phead,sltdatatype x) {
	ln* cur = phead;
	while (cur != NULL) {
		if (cur->x == x) {
			return cur;
		}
		cur = cur->next;
	}
}
//������pos��
void listinsert(ln* pos, sltdatatype x) {
	ln* new = (ln*)malloc(sizeof(ln));
	new->x = x;
	new->next = pos->next;
	pos->next = new;
}
//����
void destroylist(ln** phead) { //Ҫ������ָ�룬��Ϊ��print��plist��δ����Ϊ�ա�
	
	
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