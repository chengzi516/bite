#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef int sqdatatype; //并且使用typedef来方便更改数据类型
 typedef struct seqlist
{
	 sqdatatype* arr;
	int size; // 有效数据个数
	int capacity;//容量
}SL;//简写seqlist

//初始化
void seqlistinit( SL* ps)  //SL *ps等价于 struct seqlst *ps
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
//检查容量够不够
void seqlistcheck(SL* ps)
{
	if (ps->size == ps->capacity) //满了就进行扩容
	{
		int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		//一般扩2倍
		sqdatatype* tmp = (sqdatatype*)realloc(ps->arr, newcapacity * sizeof(sqdatatype));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->arr = tmp;
			ps->capacity = newcapacity;
		}
	}
}
//尾插
void seqlistpushback(SL* ps, sqdatatype x)
{
	
	seqlistcheck(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}
//头插
void seqlistpushfront(SL *ps,sqdatatype x)
{
	seqlistcheck(ps);
	int end = ps->size - 1;  //最后一个位置
	while (end >= 0)
	{
		ps->arr[end+1] = ps->arr[end ];
		end--;
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void seqlistpopback(SL *ps)
{
	assert(ps->size > 0);//断言
	ps->arr[ps->size - 1] = 0;//这句有无都ok
	ps->size--;
}
//头删
void seqlistpopfront(SL* ps)
{
	int start = 1;
	while (start < ps->size)
	{
		ps->arr[start - 1] = ps->arr[start];
		start++;
	}
	ps->size--;
}
//任意位置插入
void seqlistinsert(SL* ps,int pos,sqdatatype x)
{
	//pos的位置有合法性限制
	assert(pos < ps->size);
	//仍然要检查内存是否足够。
	void seqlistcheck(SL * ps);
		//给末尾数据置为end，一个一个往后挪，直到挪到pos这个位置
		int end = ps->size - 1;
		while (end >= pos)
		{
			ps->arr[end + 1] = ps->arr[end];
			--end;
		}
		ps->arr[pos] = x;
		ps->size++;
}
//任意位置删除
void seqlistderase(SL* ps, int pos)
{
	assert(pos < ps->size);
	//将要删除的元素的后一个元素下标位置记为start，从前往后向前覆盖。
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->arr[start - 1] = ps->arr[start];
		start++;
	}
	ps->size--;
}
//销毁
void seqlistdestory(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//查
void seqlistfind(SL* ps, sqdatatype x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return 1;
		}
	}
	return -1;
}
//改
void seqlistmodify(SL* ps, int pos,sqdatatype x)
{
	assert(pos < ps->size);
	ps->arr[pos] = x;

}
int main()
{
	SL s;
	seqlistinit(&s);
	seqlistpushback(&s, 1);
	seqlistpushback(&s, 2);
	seqlistpushback(&s, 3);
	seqlistpushback(&s, 4);
	seqlistpushback(&s, 5);
	seqlistpushback(&s, 6);
	seqlistpushback(&s, 7);
	seqlistpushback(&s, 8);
	seqlistpushback(&s, 9);
	seqlistpushback(&s, 10);
	seqlistpushfront(&s, 3);
	//seqlistpopback(&s);
	//seqlistpopfront(&s);
//seqlistinsert(&s, 1,20);
	//seqlistderase(&s, 1);

	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
}
int removeelement(int* nums, int numssize, int val)
{
	int src = 0;
	int dst = 0;
	while (src<numssize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
	return dst;
}
void merge(int* nums1, int* nums2, int m, int n)
{
	//将end1与2置于最后的元素
	int end1 = m - 1;
	int end2 = n - 1;
	//将end置于m+n扩充后的最后位置
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0) //有一个结束了就结束了，况且用||会导致越界
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end] = nums1[end1];//谁大就把谁的数据往nums1最后的位置那里放
			end--;
			end1--;
		}
		else
		{
			nums1[end] = nums2[end2];
			end--;
			end2--;
		}
	}
	//如果end1结束，而end2未结束，则需要将剩下的nums2的元素搬到nums1中
	while (end2 >= 0)
	{
		nums1[end] = nums2[end2];
		--end;
		--end2;
	}

}