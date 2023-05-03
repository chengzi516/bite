#pragma once
#include<iostream>
 
// 单个节点的结构体。
typedef struct node {
	struct node* next;
	int val;
	
}node;
 //链表的结构
class linklist
{
private:
    node* head;
public:
    //构造函数
    linklist();
    //析构函数
    ~linklist();
    //判空
    bool isempty();
    //取链表长度
    int length();
    //取指定位置元素
    node* getelem(int i);
    //查找元素位置
    node* findelem(int e);
   //队尾插入
    void Insert(int val);
   //指定位置插入
    void Insertindex(int val, int i);
   //删除指定位置
    void  Delete(int i);
};