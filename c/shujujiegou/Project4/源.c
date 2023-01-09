#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
typedef int datatype;
typedef struct ListNode
{
	struct ListNode* next;
    struct ListNide* prev;
	datatype data;
}listnode;
//��ʼ��
listnode* listinit()
{
	//�����½ڵ㡣
	listnode* phead = (listnode*)malloc(sizeof(listnode));
	phead->data = 0;
	phead->next =phead;  //ָ���Լ�
	phead->prev = phead;
	return phead;

}
//β��
void listpushback(listnode* phead,datatype x)
{
	listnode* tail = phead->prev;
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	newnode->data = x;
	//���Ĵ��룬�������һ��Ҫ��ͼŶ
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	
	
}
//��ӡ
void listprint(listnode* phead)
{
	listnode* p = phead->next;
	while (p != phead)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
//ͷ��
void listfrontpush(listnode* phead,datatype x)
{
	listnode* first = phead->next;
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	newnode->data = x;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

}
//ͷɾ
void listfrontpop(listnode* phead)
{
	assert(phead->next != phead);
	listnode* first = phead->next;
	listnode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}
//βɾ
void listbackpop(listnode* phead)
{
	assert(phead->next != phead);
	listnode* tail = phead->prev;
	listnode* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(tail);
}
void test()
{
	
	listnode* phead=listinit();
	listpushback(phead, 1);
	listpushback(phead, 2);
	listpushback(phead, 3);
	listpushback(phead, 4);
	listprint(phead);

	
}
int main()
{
	test();
	return 0;
}