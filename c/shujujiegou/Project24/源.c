#define _CRT_SECURE_NO_WARNINGS 1
void InsertSort(int* a, int n)
{
	assert(a);
	//最后一次，是要把n - 1这个数进行排序，则已经
	//排好序的尾部为n - 2
	for (int i = 0; i < n - 1; ++i)
	{
		//end表示已经排好序的尾标
		int end = i;
		//首先保存要排序的数，一会就会被覆盖了
		int tmp = a[end + 1];
		//只要前面的数大于end + 1,则前面的这些数都向后挪动一个位置
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	//不能写成大于0,因为gap的值始终>=1
	while (gap > 1)
	{
		//只有gap最后为1，才能保证最后有序
		//所以这里要加1
		gap = gap / 3 + 1;
		//这里只是把插入排序的1换成gap即可
		//但是这里不是排序完一个分组，再去
		//排序另一个分组，而是整体只过一遍
		//这样每次对于每组数据只排一部分
		//整个循环结束之后，所有组的数据排序完成
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}

			a[end + gap] = tmp;
		}
	}
}


void TestShellSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


