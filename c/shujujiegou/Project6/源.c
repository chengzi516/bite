#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct listnode* reverse(struct listnode* head)
{
	if (head == NULL)   //��Կ�����Ĵ���
	{
		return NULL;
	}
	struct listnode* n1 = NULL;
	struct listnode* n2 = head;
	struct listnode* n3 = n2->next;  //����ǿ�����n2��next�����
	
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)  //n3����Ϊ�գ���ôn3��nextҲ�ͻᱨ��
		{
			n3 = n3->next;
		}
	}
	//�����ͷ������n1,����⻭ͼ
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
		newhead = cur;//��newhead�����µ�ͷ
		cur = next;
	}
	return newhead;
}
struct listnode* middlenode(struct listnode* head)
{
	struct listnode* slow = head;
	struct listnode* fast= head;
	while (fast && fast->next )//��һ��Ϊ�վ�ֹͣ��
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
	while (l1 != NULL && l2 != NULL)  // һ�������Ͷ�������
	{
		if (l1->val < l2->val) //val�������ֵ���൱�����Ľ���data
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

