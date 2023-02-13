#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//书写链表的结构
//单链表，其中的指针永远只指向下一个数据
typedef int nodetype;
typedef struct slistnode
{
	nodetype data;
	struct slistnode* next;  //一个结构会包含一个数据与一个链接下一个node的指针。
}snode;

//打印函数
void print(snode* p) {
	snode* newp = p; //定义一个新指针指向头指针的位置，来不断向后移动。
	while (newp != NULL) {
		printf("%d ", newp->data);
		newp=newp->next;
	}
}
//尾插法
void nodepushback(snode** ps, nodetype x) {  //因为要改变结构的指针指向，所以要传二级指针。也可以传一级，但是返回值要是node*型。
	  //要执行插入就要先malloc出一个新节点来。
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	newp->next = NULL;  //最后一个节点的指向必须为空，否则会造成野指针的相关问题。
	if (*ps == NULL) {  //传二级指针进来，想要用就要使用解引用的操作。
		//如果传入的是第一个值。
		*ps = newp;
	}
	else
	{
		//先找到链表的尾部。
		snode* tail = *ps;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//找到后进行一个链接。
		tail->next = newp;

	}
}

//头插法
void nodepushfront(snode** ps, nodetype x) {
	//创造一个新节点。
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	newp->next = *ps; //将newp指向phead头节点。
	//别忘了将phead指向newp，成为新的头节点。
	*ps = newp;


}
//头删法
void nodepullfront(snode** ps) {
	//一定要记得释放掉第一个。
	snode* newp = (*ps)->next;
	free(*ps);
	*ps = newp;
}
//尾删法
void nodepullback(snode** ps) {
	//思路就是找到倒数第二个并置为空。记得释放掉最后一个。
	snode* tail = *ps;
	snode* prev = *ps;
	while (tail->next != NULL) {
		prev = tail;
		tail = tail->next;
	}//循环完毕，两个指针就走到了倒数第一第二的位置。
	free(tail);
	prev->next = NULL;
}
//查找
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
//插入
void nodeinsert(snode** ps, nodetype x,snode* pos) {
	//仍然需要两个指针，分别放置在pos的前后。
	//当pos等于*ps时就直接相当于头插法。
	if (pos == *ps)
		nodepushfront(ps,x);
	else {
		snode* tail = *ps;
		snode* prev = *ps;
		while (tail != pos) {
			prev = tail;
			tail = tail->next;
		}
		//申请一个新节点。
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