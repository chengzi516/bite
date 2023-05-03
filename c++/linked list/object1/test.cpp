#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

int main() {
	linklist l1;
	l1.Insert(1);
	l1.Insert(3);
	l1.Insert(5);
	l1.Insertindex(2, 2);
	/*printf("%d\n", l1.length());*/
	//node* tmp = l1.findelem(3);
	//printf("%d\n", tmp->val); 
	/*int a = l1.getelem(3);*/
	/*l1.Delete(4);
	printf("%d\n", l1.getelem(2)->val);*/
	printf("%d\n", l1.getelem(6)->val);
	return 0;
}