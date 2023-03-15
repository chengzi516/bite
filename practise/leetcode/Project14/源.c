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
 /*要求复杂度为O（n）*/

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    //第一步，拷贝每一个到原节点后面。
    struct Node* cur = head;
    while (cur) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;
        cur = cur->next->next;
    }
    //第二步，更改其拷贝节点随机指针
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
            copy->random = NULL;
        else {
            copy->random = cur->random->next;  //重点语句
        }
        cur = cur->next->next;
    }
    //第三步，将拷贝的节点都拆分下来,链接为一个新的链表，还要恢复原链表
    cur = head;
    struct Node* copyhead = (struct Node*)malloc(sizeof(struct Node));  //哨兵位
    struct Node* copytail = copyhead;
    while (cur) {
        struct Node* copy = cur->next;
        copytail->next = copy;
        copytail = copy;
        //恢复
        cur->next = cur->next->next;
        //继续
        cur = cur->next;
    }
    return copyhead->next;

}