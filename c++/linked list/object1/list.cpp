#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
#include<iostream>
#include<stdio.h>

linklist::linklist() {
	//创建一个哨兵位。
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
}

linklist:: ~linklist() {
	node* tmp = head->next;
	head = tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete(tmp);
	}   
}

bool linklist::isempty() {
	return head->next == NULL;
}

int linklist::length() {
	if (isempty())
		perror("list is null\n");
	node* tmp = head->next;
	int sum=0;
	while (tmp) {
		sum++;
		tmp = tmp->next;
	}
	return sum;
}
//完善情况。
node* linklist:: getelem(int i) {
	if (isempty())
		return NULL;
	node* tmp = head;
	while (i > 0) {
		tmp = tmp->next;
		i--;
	}
	return tmp;
}

node* linklist::findelem(int e) {
	node* tmp = head->next;
	while (tmp) {
		if (tmp->val == e) {
			printf("find it\n");
			return tmp;
		}
		tmp = tmp->next;
	}
	printf("not find\n");
	return NULL;

}

void linklist::Insert(int i) {
	node* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	node* newnode = (node*)malloc(sizeof(node));
	tmp->next = newnode;
	newnode->next = NULL;
	newnode->val = i;
}
void linklist::Insertindex(int val, int i) {
	node* tmp = findelem(--i);
	node* newnode = (node*)malloc(sizeof(node));
	newnode->val = val;
	newnode->next = tmp->next;
	tmp->next = newnode;

}

void linklist::Delete(int i) {
	if (isempty())
		perror("list is null\n");
	if (i > length())
		perror("too long\n");
	node* tmp =getelem(--i);
	node* cur = tmp->next;
	tmp->next = tmp->next->next;
	delete(cur);

}