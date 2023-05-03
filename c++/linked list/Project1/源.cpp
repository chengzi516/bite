#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
typedef struct node {
    struct node* next;
    int val;
} node;
// ����Ľṹ��
struct linklist {
    node* head;
    // ���캯��
    linklist() {
        head = new node;
        head->next = NULL;
    }
    // ��������
    ~linklist() {
        node* p = head;
        while (p != NULL) {
            node* q = p->next;
            delete p;
            p = q;
        }
    }
    // �п�
    bool isempty() {
        return head->next == NULL;
    }
    // ȡ������
    int length() {
        int len = 0;
        node* p = head->next;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        return len;
    }
    // ȡָ��λ��Ԫ��
    node* getelem(int i) {
        if (isempty()) {
            return NULL;
        }
        int j = 0;
        node* p = head->next;
        while (p != NULL && j < i) {
            j++;
            p = p->next;
        }
        return p;
    }
    // ����Ԫ��λ��
    node* findelem(int e) {
        node* p = head->next;
        while (p != NULL && p->val != e) {
            p = p->next;
        }
        return p;
    }
    // ��β����
    void Insert(int val) {
        node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        node* q = new node;
        q->val = val;
        q->next = NULL;
        p->next = q;
    }
    // ָ��λ�ò���
    void Insertindex(int val, int i) {
        if (isempty() || i < 1 || i > length()) {
            return;
        }
        node* p = getelem(i - 1);
        node* q = new node;
        q->val = val;
        q->next = p->next;
        p->next = q;
    }
    // ɾ��ָ��λ��
    void Delete(int i) {
        if (isempty() || i < 1 || i > length()) {
            return;
        }
        node* p = getelem(i - 1);
        node* q = p->next;
        p->next = q->next;
        delete q;
    }
};

int main() {
    linklist l1;
    l1.Insert(2);
    l1.Insert(4);
    l1.Insert(3);
    l1.Insert(5);
    l1.Insert(6);
    printf("%d", l1.findelem(6)->val);
}