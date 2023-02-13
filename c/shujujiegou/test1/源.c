#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//ʵ��һ����̬��˳���

typedef int listdata; //Ϊ����һ�������޸ĵ��������͡�

//��һ�����Ƕ�������Ľṹ������д��
typedef struct list {
	int maxsize;
	int currentsize;  //���嵱ǰ������������������������������ݡ�
	listdata* data; //�������ݵ�ָ�롣
}ls; //������ͼ�дΪls

//�ڶ������Ա����һ�� ��ʼ������д��ʼ������
void listinit(ls* list) {
	list->data = NULL;
	list->maxsize = 0;
	list->currentsize = 0;   //�������������г�ʼ��������׸����
}

//����������д�ж������Ƿ����˵ĺ���
void listisfull(ls* list) {
	if (list->currentsize == list->maxsize) {
		int newmaxsize = (list->maxsize == 0 ? 2 : (list->maxsize) * 2); //���maxsizeΪ0����ô���ݵ�2������maxsize������2��
		listdata* tmp = (listdata*)realloc(list->data, newmaxsize * sizeof(listdata)); 
		//ʹ��realloc��������ԭ������
		/*void* realloc(void* prr, size_t size)
			prr��Ҫ�������ڴ��ַ��
			size���´�С��
			����ֵΪ��������ڴ���ʼλ�á�
        */
		if (tmp == NULL) {
				printf("realloc fail!\n");
			}
		else{
			list->data = tmp;
			list->maxsize = newmaxsize;
		}
	}
}

//��дβ�巨
void listpushback(ls* list,listdata x) {
	listisfull(list);
	list->data[list->currentsize] = x;
	list->currentsize++;

}
//��дͷ�巨
void listpushfront(ls* list, listdata x) {
	listisfull(&list);
	int end = list->currentsize - 1;
	while (end >= 0) {
		list->data[end + 1] = list->data[end];
		end--;
	}
	list->data[0] = x;
	list->currentsize + 1;
}
//βɾ��
void listpullback(ls* list) {
	assert(list->currentsize > 0);  //���ö��ԣ���currentsizeΪ0ʱ���޷��ڽ���βɾ�ˡ�
	list->currentsize - 1;
}
//ͷɾ��
void listpullfront(ls* list) {
	assert(list->currentsize > 0);
	int start = 1;
	while (start < list->currentsize) {
		list->data[start - 1] = list->data[start];
		start++;
	}
	list->currentsize -= 1;
}
//����λ�õĲ���
void listinsert(ls* list, int pos, listdata x) {
	assert(pos < list->currentsize);
	listisfull(list);
	int end = list->currentsize - 1;
	while (end >= pos)
	{
		list->data[end + 1] = list->data[end];
		end--;
	}
	list->data[pos] = x;
	list->currentsize++;

}
//����λ�õ�ɾ��
void listpull(ls* list, int pos) {
	assert(pos < list->currentsize);
	listisfull(list);
	int end = list->currentsize - 1;
	while (end >= pos)
	{
		list->data[pos] = list->data[pos+1];
		pos++;
	}
	list->currentsize--;

}
//���Ҳ����
void listcheck(ls* list, listdata x) {
	assert(list->data != NULL);
	int flag=1;
	for (int i = 0; i < list->currentsize; i++)
	{
		if (list->data[i] == x)
		{
			printf("find it in the %d\n", i);
			flag--;
		}
		
	}
	if (flag == 1)
		printf("find fail\n");
}

//дһ����ӡ����
void print(ls* list) {
	for (int i = 0; i < list->currentsize; i++)
	{
		printf("%d ", list->data[i]);
	}
}
//�����˿ռ䣬��ô��ʹ����Ͼ�һ��Ҫ���ٵ������������ڴ�й¶��һϵ���ش�����⡣
void listdelete(ls* list) {
	free(list->data);
	listinit(list);  //������ʼ��������lista��Ϊ���Լ���0�Ȳ�����

}

int main()
{ //����list�Ĳ�����֤��
	ls lista;
	listinit(&lista);
	listpushback(&lista, 1);
	listpushback(&lista, 2);
	listpushback(&lista, 3);
	listpushback(&lista, 4);
	listpushback(&lista, 5);
	print(&lista);

}


