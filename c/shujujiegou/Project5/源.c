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
	phead->next = phead;  //ָ���Լ�
	phead->prev = phead;
	return phead;

}
//����
void listinsert(listnode* pos, datatype x)
{
	assert(pos);
	listnode* prev = pos->prev;
	//����ڵ�
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	newnode->data = x;
	newnode->next = pos;
	prev->next = newnode;
	newnode->prev = prev;
	pos->prev = newnode;

}
//β��
void listpushback(listnode* phead, datatype x)
{
	//listnode* tail = phead->prev;
	//listnode* newnode = (listnode*)malloc(sizeof(listnode));
	//newnode->data = x;
	////���Ĵ��룬�������һ��Ҫ��ͼŶ
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	
	listinsert(phead, x);


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
void listfrontpush(listnode* phead, datatype x)
{
	/*listnode* first = phead->next;
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	newnode->data = x;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;*/
	listnode* pos=phead->next;
	listinsert(pos,x);
}
//ɾ��
void listerase(listnode* pos)
{
	assert(pos);
	listnode* prev = pos->prev;
	listnode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
//ͷɾ
void listfrontpop(listnode* phead)
{
	/*assert(phead->next != phead);
	listnode* first = phead->next;
	listnode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);*/
	listerase(phead->next);
}

//βɾ
void listbackpop(listnode* phead)
{
	//assert(phead->next != phead);
	//listnode* tail = phead->prev;
	//listnode* prev = tail->prev;
	//prev->next = phead;
	//phead->prev = prev;
	//free(tail);
	listerase(phead->prev);
}
//����pos
listnode* listfind(listnode* phead, datatype x)
{
	assert(phead);
	listnode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void test()
{

	listnode* phead = listinit();
	listpushback(phead, 1);
	listpushback(phead, 2);
	listpushback(phead, 3);
	listpushback(phead, 4);

	//listpushback(phead, 9);
	/*listnode* pos = listfind(phead, 4);
	listerase(pos);*/
	listprint(phead);


}
int main()
{
	test();
	return 0;
}