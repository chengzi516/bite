#pragma once
#include<iostream>
 
// �����ڵ�Ľṹ�塣
typedef struct node {
	struct node* next;
	int val;
	
}node;
 //����Ľṹ
class linklist
{
private:
    node* head;
public:
    //���캯��
    linklist();
    //��������
    ~linklist();
    //�п�
    bool isempty();
    //ȡ������
    int length();
    //ȡָ��λ��Ԫ��
    node* getelem(int i);
    //����Ԫ��λ��
    node* findelem(int e);
   //��β����
    void Insert(int val);
   //ָ��λ�ò���
    void Insertindex(int val, int i);
   //ɾ��ָ��λ��
    void  Delete(int i);
};