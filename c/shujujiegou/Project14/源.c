#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct binarytreenode {
	int val;
	struct binarytreenode* left;
	struct binarytreenode* right;
}btnode;
btnode* creatnode(int x) {
	btnode* newnode = (btnode*)malloc(sizeof(btnode));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->val = x;
	return newnode;

}
//void levelorder(btnode* root) {
//	assert(root);
//    if (root != NULL)
//    {
//        push(root->val);   //���ڵ������
//    }
//
//    while (!empty())  //���в�Ϊ���ж�
//    {
//        printf("%d->", root->val);
//
//        if (root->left)   //��������ӣ�leftChild�����
//        {
//            push(root->left->val);
//            root = root->left;
//        }
//
//        if (root->right)   //������Һ��ӣ�rightChild�����
//        {
//            push(root->right->val);
//            if (!(root->left))
//                root = root->right;
//        }
//        pop();  //�Ѿ��������Ľڵ������
//
//    }
//}
void PreOrder(btnode* root) {
    if (root == NULL) {
        printf("NULL->");
        return;
    }
    printf("%d->", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(btnode* root) {
    if (root == NULL) {
        printf("NULL->");
        return;
    }
    InOrder(root->left);
    printf("%d->", root->val);
    InOrder(root->right);
}
void PostOrder(btnode* root)
{
    if (root == NULL)
    {
        printf("NULL->");
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d->", root->val);
}
int treesize(btnode* root) {
    if (root == NULL)
        return 0;
    return treesize(root->left) + treesize(root->right) + 1;
}
int TreeHeight(btnode* root)
{
    if (root == NULL)
        return 0;
    int leftHeight = TreeHeight(root->left);
    int rightHeight = TreeHeight(root->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
int treeklevel(btnode* root, int k) {
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;

    return TreeKLevel(root->left, k - 1)+ TreeKLevel(root->right, k - 1);

}

int main() {
    btnode* a = creatnode(1);
    btnode* b = creatnode(3);
    btnode* c = creatnode(7);
    btnode* d = creatnode(4);
    btnode* e = creatnode(5);
    btnode* f = creatnode(6);
    btnode* g = creatnode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    d->left = g;
    //PostOrder(a);
    printf("%d", treesize(a));
}