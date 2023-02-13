#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//��д����Ľṹ
//���������е�ָ����Զָֻ����һ������
typedef int nodetype;
typedef struct slistnode
{
	nodetype data;
	struct slistnode* next;  //һ���ṹ�����һ��������һ��������һ��node��ָ�롣
}snode;

//��ӡ����
void print(snode* p) {
	snode* newp = p; //����һ����ָ��ָ��ͷָ���λ�ã�����������ƶ���
	while (newp != NULL) {
		printf("%d ", newp->data);
		newp=newp->next;
	}
}
//β�巨
void nodepushback(snode** ps, nodetype x) {  //��ΪҪ�ı�ṹ��ָ��ָ������Ҫ������ָ�롣Ҳ���Դ�һ�������Ƿ���ֵҪ��node*�͡�
	  //Ҫִ�в����Ҫ��malloc��һ���½ڵ�����
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	newp->next = NULL;  //���һ���ڵ��ָ�����Ϊ�գ���������Ұָ���������⡣
	if (*ps == NULL) {  //������ָ���������Ҫ�þ�Ҫʹ�ý����õĲ�����
		//���������ǵ�һ��ֵ��
		*ps = newp;
	}
	else
	{
		//���ҵ������β����
		snode* tail = *ps;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//�ҵ������һ�����ӡ�
		tail->next = newp;

	}
}

//ͷ�巨
void nodepushfront(snode** ps, nodetype x) {
	//����һ���½ڵ㡣
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	newp->next = *ps; //��newpָ��pheadͷ�ڵ㡣
	//�����˽�pheadָ��newp����Ϊ�µ�ͷ�ڵ㡣
	*ps = newp;


}
//ͷɾ��
void nodepullfront(snode** ps) {
	//һ��Ҫ�ǵ��ͷŵ���һ����
	snode* newp = (*ps)->next;
	free(*ps);
	*ps = newp;
}
//βɾ��
void nodepullback(snode** ps) {
	//˼·�����ҵ������ڶ�������Ϊ�ա��ǵ��ͷŵ����һ����
	snode* tail = *ps;
	snode* prev = *ps;
	while (tail->next != NULL) {
		prev = tail;
		tail = tail->next;
	}//ѭ����ϣ�����ָ����ߵ��˵�����һ�ڶ���λ�á�
	free(tail);
	prev->next = NULL;
}
//����
void nodecheck(snode** ps, nodetype x) {
	snode* newp = *ps;
	int flag = 1;
	while ((newp->next)!=NULL) {
		if (newp->data == x) {
			printf("find it!\n");
			flag--;
			
	   }
		newp = newp->next;
	}
	if (flag == 1)
		printf("find fail\n");
}
//����
void nodeinsert(snode** ps, nodetype x,snode* pos) {
	//��Ȼ��Ҫ����ָ�룬�ֱ������pos��ǰ��
	//��pos����*psʱ��ֱ���൱��ͷ�巨��
	if (pos == *ps)
		nodepushfront(ps,x);
	else {
		snode* tail = *ps;
		snode* prev = *ps;
		while (tail != pos) {
			prev = tail;
			tail = tail->next;
		}
		//����һ���½ڵ㡣
		snode* newp = (snode*)malloc(sizeof(snode));
		newp->data = x;
		newp->next = tail;
		prev->next = newp;
	}
}
int main() {
	snode* phead=NULL;
	nodepushback(&phead,1);
	nodepushback(&phead,2);
	nodepushback(&phead,3);
	nodepushback(&phead,4);
	nodepushback(&phead,5);
	nodepushback(&phead,6);
	nodepushback(&phead,7);
	nodeinsert(&phead, 10, phead);
	//nodepullfront(&phead);
	//nodepullback(&phead);
	//nodecheck(&phead, 5);
	print(phead);
}