#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct treenode
{
	struct treenode* left;
	struct treenode* right;
	char data;
}tn;
//前序
void prevorder(tn* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	prevorder(root->left);
	prevorder(root->right);
}
//中序
void inorder(tn* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	inorder(root->left);
	printf("%c ", root->data);
	inorder(root->right);

}
//后序
void postorder(tn* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%c ", root->data);

}
//求节点个数
int size = 0;
void treesize(tn* root,int*psize)
{
	if (root == NULL)
	{
		return;
	}
	++(*psize);
	treesize(root->left,psize);
	treesize(root->right,psize);
}
//解法2
int treesize2(tn* root)
{
	return root == NULL ? 0 : treesize2(root->left) + treesize2(root->right) + 1;
}
//求叶子节点个数
int treeleafsize(tn* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return treeleafsize(root->left) + treeleafsize(root->right);
}
int main()
{
	tn* a = (tn*)malloc(sizeof(tn));
	a->data = 'a';
	a->left = NULL;
	a->right = NULL;
	tn* b = (tn*)malloc(sizeof(tn));
	b->data = 'b';
	b->left = NULL;
	b->right = NULL;
	tn* c = (tn*)malloc(sizeof(tn));
	c->data = 'c';
	c->left = NULL;
	c->right = NULL;
	tn* d = (tn*)malloc(sizeof(tn));
	d->data = 'd';
	d->left = NULL;
	d->right = NULL;
	tn* e = (tn*)malloc(sizeof(tn));
	e->data = 'e';
	e->left = NULL;
	e->right = NULL;
	tn* f = (tn*)malloc(sizeof(tn));
	f->data = 'f';
	f->left = NULL;
	f->right = NULL;
	tn* g = (tn*)malloc(sizeof(tn));
    g->data = 'g';
	g->left = NULL;
	g->right = NULL;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	postorder(a);

}