#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node* next;
    int num;
}node;
node* buynode(int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->num = x;
    return newnode;
}
void pushback(node** p, int x) {
    node* newnode = buynode(x);
    if (*p == NULL)
        (*p) = newnode;
    else {
        node* tail = *p;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = newnode;
    }
}
node* pop(node* cur) {
    
    node* p = cur;
    while (p->next != cur) {
        p = p->next;
    }
    p->next = cur->next;
    free(cur);
    return p->next;
}
int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    node* head = NULL;
    //创建链表
    for (int i = 0; i < n; i++) {
        pushback(&head, i + 1);
    }
    node* cur = head;
    node* tail = cur;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = head;
    //pop指定节点
    while (cur->next !=cur) {
        
            for (int i = 0; i < m - 1; i++) {
                cur = cur->next;

            }
         cur=pop(cur);
         
        
    }
    printf("%d",cur->num);
}