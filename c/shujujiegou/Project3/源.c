#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct slistnode
{
	datatype data;
	struct slistnode* next;//指向这种类型的指针，但注意，结构体不能嵌套结构体哦

}snode;
//打印链表
void printslist(snode* phead)
{   //创建一个指针指向phead的下一个节点
	snode* cur = phead;
	while (cur != NULL)  //当cur移动到NULL时，即遍历完整个链表。
	{
		printf("%d ", cur->data);
		cur = cur->next; //cur指向此结构体中的next，也就是下一个节点的data。
	}

}
//尾插
void slistpushback(snode** pphead,datatype x)
{
	snode* newnode = (snode*)malloc(sizeof(snode));//创建一个新节点
	newnode->data = x;
	newnode->next = NULL;//注意不要忘了最后一个节点的next指向NULL哦
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//利用tail来找链表尾巴
		snode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//链接尾节点
		tail->next = newnode;
	}
}
//头插
void slistpushfront(snode** pphead, datatype x)
{
	snode* newnode = (snode*)malloc(sizeof(snode));//创建一个新节点
	newnode->data = x;
	newnode->next = NULL;//注意不要忘了最后一个节点的next指向NULL哦
	newnode->next = *pphead;
	*pphead = newnode;
}
//头删
void slistpopfront(snode** pphead)
{
	//用一个指针保存头节点的next（也就是第二个节点），再释放第一个节点
	snode* next = (*pphead)->next;
	free(*pphead);
	//将第二个节点地址存入phead
	*pphead = next;
}
//尾删
void slistpopback(snode** pphead)
{
	//主要是要找到尾的前一个，将其置向null，不然就成了野指针了。

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
//查找
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
//插入
void slistinsert(snode** pphead, snode* pos, datatype x)
{
	if (pos == *pphead)  // 当pos就在第一个位置时，直接相当于头插，如果不这样，prev无法判断pos位，他的起始判断位置就在prev->next
	{
		slistpushfront(pphead, x);
	}
	else
	{

		snode* newnode = (snode*)malloc(sizeof(snode));//创建一个新节点
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
//删除
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
	//插入
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