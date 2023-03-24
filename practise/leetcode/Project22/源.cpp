#define _CRT_SECURE_NO_WARNINGS 1
void HeapSort(int* a, int n)
{

	// 建堆 -- 向下调整建堆 -- O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		adjustdown(a, n, i);
	}

	// 自己先实现 -- O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[end], &a[0]);
		adjustdown(a, end, 0);

		--end;
	}
}