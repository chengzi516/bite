#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
 /*Ҫ���Ӷ�ΪO��n��*/

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    //��һ��������ÿһ����ԭ�ڵ���档
    struct Node* cur = head;
    while (cur) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;
        cur = cur->next->next;
    }
    //�ڶ����������俽���ڵ����ָ��
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
            copy->random = NULL;
        else {
            copy->random = cur->random->next;  //�ص����
        }
        cur = cur->next->next;
    }
    //���������������Ľڵ㶼�������,����Ϊһ���µ�������Ҫ�ָ�ԭ����
    cur = head;
    struct Node* copyhead = (struct Node*)malloc(sizeof(struct Node));  //�ڱ�λ
    struct Node* copytail = copyhead;
    while (cur) {
        struct Node* copy = cur->next;
        copytail->next = copy;
        copytail = copy;
        //�ָ�
        cur->next = cur->next->next;
        //����
        cur = cur->next;
    }
    return copyhead->next;

}