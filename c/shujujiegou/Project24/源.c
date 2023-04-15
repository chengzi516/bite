#define _CRT_SECURE_NO_WARNINGS 1
void InsertSort(int* a, int n)
{
	assert(a);
	//���һ�Σ���Ҫ��n - 1����������������Ѿ�
	//�ź����β��Ϊn - 2
	for (int i = 0; i < n - 1; ++i)
	{
		//end��ʾ�Ѿ��ź����β��
		int end = i;
		//���ȱ���Ҫ���������һ��ͻᱻ������
		int tmp = a[end + 1];
		//ֻҪǰ���������end + 1,��ǰ�����Щ�������Ų��һ��λ��
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
	//����д�ɴ���0,��Ϊgap��ֵʼ��>=1
	while (gap > 1)
	{
		//ֻ��gap���Ϊ1�����ܱ�֤�������
		//��������Ҫ��1
		gap = gap / 3 + 1;
		//����ֻ�ǰѲ��������1����gap����
		//�������ﲻ��������һ�����飬��ȥ
		//������һ�����飬��������ֻ��һ��
		//����ÿ�ζ���ÿ������ֻ��һ����
		//����ѭ������֮��������������������
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


