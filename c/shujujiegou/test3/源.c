#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��д˫������������Ϊ��ͷ˫��ѭ������
typedef int datatype;
typedef struct snode {
	datatype data;
	struct snode* prev;
	struct snode* next; // ʵ��˫�����Ҫ����ָ�룬�ֱ�ָ��ǰ��ͺ��档
}snode;

//��������г�ʼ����
snode* nodeinit() { //Ҳ�ɲ�ȡ����ָ�봫�η�ʽ��
	// �ڱ��ڵ�㷺Ӧ�������������У���αͷ��αβ����ǵȣ������Ǵ����ܵģ�ͨ���������κ����ݣ�����ҪĿ����ʹ�����׼������ʹ��������Ϊ�ա�������ͷ���򻯲����ɾ����
	snode* soilder = (snode*)malloc(sizeof(snode));
	soilder->next = soilder;
	soilder->prev = soilder;
	soilder->data = 0; //������ָ�붼��ָ���Լ���������ĵط������չʾ��
	return soilder;
}
//β�巨
void nodepushback(snode* phead,datatype x) {//��������ͷ�ڵ㣬�Ͳ������if NULL��phead=newp�������Ҳ���ǲ���ȥ�ı�phead��������ֱ�ӽ������ӡ�
	 //�ҵ�βtail��
	snode* tail = phead->prev; //˫��ĺô��������
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	tail->next = newp;
	newp->next = phead;
	newp->prev = tail;
	phead->prev = newp;
}
//��ӡ����
void print(snode* phead) {
	snode* newp = phead->next;
	while (newp != phead) {
		printf("%d ", newp->data);
		newp = newp->next;
	}

}
//ͷ�巨
void nodepushfront(snode* phead,datatype x) {
	//ֱ����phead�����
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->prev = phead;
	newp->data = x;
	newp->next = phead->next;
	phead->next->prev = newp;
	phead->next = newp;  //Ҳ�����Ƚ���һ���ڵ㱣�����������������׶���
}
//ͷɾ��
void nodepopfront(snode* phead) {
	//ע��ֻʣphead�ͱ�ɾ�ˡ�
	assert(phead->next != phead);
	snode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
}
//βɾ��
void nodepopback(snode* phead) {
	assert(phead->next != phead);
	snode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
}
//����
void nodeinsert(snode* pos, datatype x) {
	assert(pos);
	snode* newp = (snode*)malloc(sizeof(snode));
	newp->data = x;
	newp->next = pos;
	newp->prev = pos->prev;
	pos->prev->next = newp;
	pos->prev = newp;
}
//ɾ��
void nodedelete(snode* pos) {
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//����ɾ����������Ϳ����Դ��븴�õ���ʽ����дͷɾβɾͷ��β�����ֲ�����
// βɾ�� nodedelete(phead->prev);
int main() {
	snode* phead = nodeinit();
	nodepushback(phead, 1);
	nodepushback(phead, 2);
	nodepushback(phead, 3);
	nodepushback(phead, 4);
	nodepushfront(phead, 5);
	//nodepopfront(phead);
	nodeinsert(phead->next->next->next, 10);
	nodedelete(phead->next->next->next);
	//βɾ����д
	nodedelete(phead->prev);
	//ͷɾ
	nodedelete(phead->next);
	//ͷ��
	nodeinsert(phead->next, 100);
	//β��
	nodeinsert(phead, 1000);



	print(phead);
}