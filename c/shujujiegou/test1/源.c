#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//实现一个动态的顺序表

typedef int listdata; //为表创建一个方便修改的数据类型。

//第一步就是对整个表的结构进行书写。
typedef struct list {
	int maxsize;
	int currentsize;  //定义当前容量与允许的最大容量，方便进行扩容。
	listdata* data; //放入数据的指针。
}ls; //表的类型简写为ls

//第二步，对表进行一个 初始化，书写初始化函数
void listinit(ls* list) {
	list->data = NULL;
	list->maxsize = 0;
	list->currentsize = 0;   //对三个变量进行初始化，不多赘述。
}

//第三步，书写判断容量是否满了的函数
void listisfull(ls* list) {
	if (list->currentsize == list->maxsize) {
		int newmaxsize = (list->maxsize == 0 ? 2 : (list->maxsize) * 2); //如果maxsize为0，那么扩容到2，否则将maxsize扩容至2倍
		listdata* tmp = (listdata*)realloc(list->data, newmaxsize * sizeof(listdata)); 
		//使用realloc函数，其原型如下
		/*void* realloc(void* prr, size_t size)
			prr是要调整的内存地址。
			size是新大小！
			返回值为调整后的内存起始位置。
        */
		if (tmp == NULL) {
				printf("realloc fail!\n");
			}
		else{
			list->data = tmp;
			list->maxsize = newmaxsize;
		}
	}
}

//书写尾插法
void listpushback(ls* list,listdata x) {
	listisfull(list);
	list->data[list->currentsize] = x;
	list->currentsize++;

}
//书写头插法
void listpushfront(ls* list, listdata x) {
	listisfull(&list);
	int end = list->currentsize - 1;
	while (end >= 0) {
		list->data[end + 1] = list->data[end];
		end--;
	}
	list->data[0] = x;
	list->currentsize + 1;
}
//尾删法
void listpullback(ls* list) {
	assert(list->currentsize > 0);  //运用断言，当currentsize为0时就无法在进行尾删了。
	list->currentsize - 1;
}
//头删法
void listpullfront(ls* list) {
	assert(list->currentsize > 0);
	int start = 1;
	while (start < list->currentsize) {
		list->data[start - 1] = list->data[start];
		start++;
	}
	list->currentsize -= 1;
}
//任意位置的插入
void listinsert(ls* list, int pos, listdata x) {
	assert(pos < list->currentsize);
	listisfull(list);
	int end = list->currentsize - 1;
	while (end >= pos)
	{
		list->data[end + 1] = list->data[end];
		end--;
	}
	list->data[pos] = x;
	list->currentsize++;

}
//任意位置的删除
void listpull(ls* list, int pos) {
	assert(pos < list->currentsize);
	listisfull(list);
	int end = list->currentsize - 1;
	while (end >= pos)
	{
		list->data[pos] = list->data[pos+1];
		pos++;
	}
	list->currentsize--;

}
//查找并输出
void listcheck(ls* list, listdata x) {
	assert(list->data != NULL);
	int flag=1;
	for (int i = 0; i < list->currentsize; i++)
	{
		if (list->data[i] == x)
		{
			printf("find it in the %d\n", i);
			flag--;
		}
		
	}
	if (flag == 1)
		printf("find fail\n");
}

//写一个打印函数
void print(ls* list) {
	for (int i = 0; i < list->currentsize; i++)
	{
		printf("%d ", list->data[i]);
	}
}
//申请了空间，那么当使用完毕就一定要销毁掉，否则会造成内存泄露等一系列重大的问题。
void listdelete(ls* list) {
	free(list->data);
	listinit(list);  //借助初始化函数将lista置为空以及置0等操作。

}

int main()
{ //对于list的操作验证。
	ls lista;
	listinit(&lista);
	listpushback(&lista, 1);
	listpushback(&lista, 2);
	listpushback(&lista, 3);
	listpushback(&lista, 4);
	listpushback(&lista, 5);
	print(&lista);

}


