#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int GetMidNumi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//霍尔排序
//int PartSort1(int* a, int left, int right) {
//	if (left >= right)
//			return;
//		
//	int begin = left, end = right;
//	// 三数取中
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//			--right;
//		while (left < right && a[left] <= a[keyi])
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//
//	Swap(&a[keyi], &a[left]);
//	QuickSort1(a, begin, keyi - 1);
//	QuickSort1(a, keyi+1, end);
//}
//// 快速排序挖坑法
//int PartSort2(int* a, int left, int right) {
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//	int key = a[left];
//	int hole = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= key)
//			--right;
//
//		a[hole] = a[right];
//		hole = right;
//		while (left < right && a[left] <= key)
//			++left;
//		a[hole] = a[left];
//		hole = left;
//	}
//
//	a[hole] = key;
//	return hole;
//}
//// 快速排序前后指针法
//int PartSort3(int* a, int left, int right) {
//	// 三数取中
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//
//	int keyi = left;
//
//	int prev = left;
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//			Swap(&a[cur], &a[prev]);
//
//		++cur;
//	}
//
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//
//	return keyi;
//}
//void QuickSort(int* a, int left, int right) {
//	if (left >= right)
//		return;
//
//	int keyi = PartSort3(a, left, right);
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi + 1, right);
//}
void quick_sort(int* nums, int left, int right) {
	if (left >= right)
		return;
	int i = left - 1;
	int j = right + 1;
	int key = nums[left + right >> 1];
	while (i < j) {
		do { i++; } while (nums[i] < key);
		do { j++; } while (nums[j] > key);
		if (i < j)
			Swap(&nums[i], &nums[j]);
	}
	quick_sort(nums, left, j);
	quick_sort(nums, j + 1, right);

}
int* sortArray(int* nums, int numsSize) {
	quick_sort(nums, 0, numsSize - 1);
	return nums;
}
int main() {
	int nums[] = { 5,2,3,1 };
	sortArray(nums, 4);
}