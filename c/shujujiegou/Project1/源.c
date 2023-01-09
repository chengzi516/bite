#define _CRT_SECURE_NO_WARNINGS 1
//void func1(int N) {
//	int count = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; k++) {
//		++count;
//	}
//	int M = 10;
//	while (M--) {
//		++count;
//	}
//	printf("%d", count);
//
//}
//void func2(int N, int M) {
//	int count = 0;
//	for (int k = 0; k < M, k++) {
//		++count;
//	}
//	for (int k = 0; k < N; k++) {
//		++count;
//	}
//
//
//
//long long factorial(size_t N)
//{
//	return N < 2 ? N : factorial(N - 1) * N;
//}
//void bubblesort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 1)
//		{
//			break;
//		}
//	}
//}heheeheheheh
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int num[] = { 0,1,2,3,4,6,7,8,9,};
//	//a先与数组中的数进行异或。
//	for (int i = 0; i < sizeof(num)/sizeof(num[1]); i++)
//	{
//		a ^= num[i];
//	}
//	// 
//	for (int j = 0; j < sizeof(num) / sizeof(num[1]) + 1; j++)
//	{
//		a ^= j;
//	}
//	printf("%d", a);
//}
//void rotate(int* nums, int numsize, int k)
//{
//	while (k--)
//	{
//		int temp = nums[numsize - 1];
//		for (int i = numsize - 2; i >= 0; --i)
//		{
//			nums[i + 1] = nums[i];
//		}
//		nums[0] = temp;
//	}
//}

void reverse(int *nums,int left,int right)
{
	int temp;
	while (left < right)
	{
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		++left;
		--right;
	}

}
void rotate(int* nums, int numsize, int k)
{
	if (k >= numsize)
	{
		k %= numsize;
	}
	reverse(nums, numsize - k, nums - 1);
	reverse(nums, 0, numsize -k- 1);
	reverse(nums, 0, numsize - 1);
}