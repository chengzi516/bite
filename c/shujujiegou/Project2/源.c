#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef int sqdatatype; //����ʹ��typedef�����������������
 typedef struct seqlist
{
	 sqdatatype* arr;
	int size; // ��Ч���ݸ���
	int capacity;//����
}SL;//��дseqlist

//��ʼ��
void seqlistinit( SL* ps)  //SL *ps�ȼ��� struct seqlst *ps
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
//�������������
void seqlistcheck(SL* ps)
{
	if (ps->size == ps->capacity) //���˾ͽ�������
	{
		int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		//һ����2��
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
//β��
void seqlistpushback(SL* ps, sqdatatype x)
{
	
	seqlistcheck(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}
//ͷ��
void seqlistpushfront(SL *ps,sqdatatype x)
{
	seqlistcheck(ps);
	int end = ps->size - 1;  //���һ��λ��
	while (end >= 0)
	{
		ps->arr[end+1] = ps->arr[end ];
		end--;
	}
	ps->arr[0] = x;
	ps->size++;
}

//βɾ
void seqlistpopback(SL *ps)
{
	assert(ps->size > 0);//����
	ps->arr[ps->size - 1] = 0;//������޶�ok
	ps->size--;
}
//ͷɾ
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
//����λ�ò���
void seqlistinsert(SL* ps,int pos,sqdatatype x)
{
	//pos��λ���кϷ�������
	assert(pos < ps->size);
	//��ȻҪ����ڴ��Ƿ��㹻��
	void seqlistcheck(SL * ps);
		//��ĩβ������Ϊend��һ��һ������Ų��ֱ��Ų��pos���λ��
		int end = ps->size - 1;
		while (end >= pos)
		{
			ps->arr[end + 1] = ps->arr[end];
			--end;
		}
		ps->arr[pos] = x;
		ps->size++;
}
//����λ��ɾ��
void seqlistderase(SL* ps, int pos)
{
	assert(pos < ps->size);
	//��Ҫɾ����Ԫ�صĺ�һ��Ԫ���±�λ�ü�Ϊstart����ǰ������ǰ���ǡ�
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->arr[start - 1] = ps->arr[start];
		start++;
	}
	ps->size--;
}
//����
void seqlistdestory(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//��
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
//��
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
	//��end1��2��������Ԫ��
	int end1 = m - 1;
	int end2 = n - 1;
	//��end����m+n���������λ��
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0) //��һ�������˾ͽ����ˣ�������||�ᵼ��Խ��
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end] = nums1[end1];//˭��Ͱ�˭��������nums1����λ�������
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
	//���end1��������end2δ����������Ҫ��ʣ�µ�nums2��Ԫ�ذᵽnums1��
	while (end2 >= 0)
	{
		nums1[end] = nums2[end2];
		--end;
		--end2;
	}

}