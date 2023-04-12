#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void mergesort(int* a, int left, int right) {
	if (left >= right)
		return;
	int mid = (left + right >> 1);
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	//开辟一个新数组来进行排序
	int tmp[1000];
	int k = 0; //k是他的下标
	int i = left;
	int j = mid+1;  //i和j是被分成了两部分后的两个数组的开头下标
	while (i <= mid && j <= right) {
		if (a[i] > a[j])
			tmp[k++] = a[j++];
		else
			tmp[k++] = a[i++];
	}
	//处理可能剩下来的两个数组中的一个
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= right) tmp[k++] = a[j++];
	//进行拷贝
	for (int i = left, k = 0; i <= right; i++, k++) {  //i必须等于l，因为是从l开始拷贝，而不是0
		a[i] = tmp[k];
	}
}
//使用非递归来实现归并排序
void mergesortnonr(int* a, int numsize) {
	/*mergesort(a, left, mid);
	mergesort(a, mid + 1, right);*/
	int gap = 1;
	while (gap < numsize) {
		for (int q = 0; q <numsize; q += 2 * gap) {
			int begin = q;//记录一下此时的数组开始下标
			int i = q;
			int j= q + gap;
			int iend=q+gap-1;
			int jend = q + 2 * gap - 1;  //jend就是此时数组的结束下标
			//对越界的情况进行一个修正
			if (iend >= numsize || j >= numsize) //iend越过了数组边界或者j越过了数组边界，二者是一种情况
			{
				break;
			}

			if (jend >= numsize)  //jend越过了数组边界
			{
			  	jend = numsize - 1;   //手动修正到边界上来
			}
			//开辟一个新数组来进行排序
			int tmp[1000];
			int k = 0; //k是他的下标
			
			while (i <= iend && j <= jend) {
				if (a[i] > a[j])
					tmp[k++] = a[j++];
				else
					tmp[k++] = a[i++];
			}
			//处理可能剩下来的两个数组中的一个
			while (i <= iend) tmp[k++] = a[i++];
			while (j <= jend) tmp[k++] = a[j++];
			//进行拷贝
			for (int i =begin , k = 0; i <= jend; i++, k++) {  //i必须等于l，因为是从l开始拷贝，而不是0
				a[i] = tmp[k];
			}
		}
		gap *= 2;
	}
}
int  main() {
	int arr[] = { 25,654,23,27,68,49,80,90,12,44,12};
	mergesortnonr(arr,11);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}