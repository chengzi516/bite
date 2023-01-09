#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct listnode* reverse(struct listnode* head)
{
	if (head == NULL)   //针对空链表的处理。
	{
		return NULL;
	}
	struct listnode* n1 = NULL;
	struct listnode* n2 = head;
	struct listnode* n3 = n2->next;  //如果是空链表，n2的next会出错。
	
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)  //n3可能为空，那么n3的next也就会报错
		{
			n3 = n3->next;
		}
	}
	//链表的头换成了n1,不理解画图
	return n1;

}
struct listnode* reverse(struct listnode* head)
{
	struct listnode* cur = head;
	struct listnode* newhead = NULL;
	while (cur)
	{
		struct listnode* next = cur->next;
		cur->next = newhead;
		newhead = cur;//将newhead当作新的头
		cur = next;
	}
	return newhead;
}
struct listnode* middlenode(struct listnode* head)
{
	struct listnode* slow = head;
	struct listnode* fast= head;
	while (fast && fast->next )//有一个为空就停止。
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
struct listnode* mergetwolists(struct listnode* l1, struct listnode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct listnode* head = NULL;
	struct listnode* tail = NULL;
	while (l1 != NULL && l2 != NULL)  // 一个结束就都结束了
	{
		if (l1->val < l2->val) //val是题给的值，相当于上文讲的data
		{
			if (tail == NULL)
			{
				head = tail = l1;
			}
			else
			{
				tail->next = l1;
				tail = tail->next;
			}
			l1 = l1->next;
		}
		else
		{
			if (tail == NULL)
			{
				head = tail = l2;
			}
			else
			{
				tail->next = l2;
				tail = tail->next;
			}
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
	{
		tail->next = l1;
	}
	if (l2 != NULL)
	{
		tail->next = l2;
	}
	
}

