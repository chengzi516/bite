#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct slistnode
{
	datatype data;
	struct slistnode* next;//ָ���������͵�ָ�룬��ע�⣬�ṹ�岻��Ƕ�׽ṹ��Ŷ

}snode;
//��ӡ����
void printslist(snode* phead)
{   //����һ��ָ��ָ��phead����һ���ڵ�
	snode* cur = phead;
	while (cur != NULL)  //��cur�ƶ���NULLʱ������������������
	{
		printf("%d ", cur->data);
		cur = cur->next; //curָ��˽ṹ���е�next��Ҳ������һ���ڵ��data��
	}

}
//β��
void slistpushback(snode** pphead,datatype x)
{
	snode* newnode = (snode*)malloc(sizeof(snode));//����һ���½ڵ�
	newnode->data = x;
	newnode->next = NULL;//ע�ⲻҪ�������һ���ڵ��nextָ��NULLŶ
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//����tail��������β��
		snode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//����β�ڵ�
		tail->next = newnode;
	}
}
//ͷ��
void slistpushfront(snode** pphead, datatype x)
{
	snode* newnode = (snode*)malloc(sizeof(snode));//����һ���½ڵ�
	newnode->data = x;
	newnode->next = NULL;//ע�ⲻҪ�������һ���ڵ��nextָ��NULLŶ
	newnode->next = *pphead;
	*pphead = newnode;
}
//ͷɾ
void slistpopfront(snode** pphead)
{
	//��һ��ָ�뱣��ͷ�ڵ��next��Ҳ���ǵڶ����ڵ㣩�����ͷŵ�һ���ڵ�
	snode* next = (*pphead)->next;
	free(*pphead);
	//���ڶ����ڵ��ַ����phead
	*pphead = next;
}
//βɾ
void slistpopback(snode** pphead)
{
	//��Ҫ��Ҫ�ҵ�β��ǰһ������������null����Ȼ�ͳ���Ұָ���ˡ�

	if (*pphead==NULL)  
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	snode* prev = NULL;
	snode* tail = *pphead;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL;
}
//����
snode* slistfind(snode* phead, datatype x)
{
	snode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//����
void slistinsert(snode** pphead, snode* pos, datatype x)
{
	if (pos == *pphead)  // ��pos���ڵ�һ��λ��ʱ��ֱ���൱��ͷ�壬�����������prev�޷��ж�posλ��������ʼ�ж�λ�þ���prev->next
	{
		slistpushfront(pphead, x);
	}
	else
	{

		snode* newnode = (snode*)malloc(sizeof(snode));//����һ���½ڵ�
		newnode->data = x;
		newnode->next = NULL;
		snode* prev = *pphead;
		while ((prev->next) != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
//ɾ��
void slisterase(snode** pphead, snode* pos)
{
	if (pos == *pphead)
	{
		slistpopfront(pphead);
	}
	else
	{
		snode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
void testlist()
{
	snode* phead = NULL;
	slistpushback(&phead, 3);
	slistpushback(&phead, 3);
	slistpushback(&phead, 4);
	slistpushback(&phead, 3);
	slistpushfront(&phead, 2);
	//����
	snode* pos = slistfind(phead, 2);
	if (pos)
	{
		slisterase(&phead, pos);
	}
	printslist(phead);
}
int main()
{
	testlist();
	return 0;
}