#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void mergesort(int* a, int left, int right) {
	if (left >= right)
		return;
	int mid = (left + right >> 1);
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	//����һ������������������
	int tmp[1000];
	int k = 0; //k�������±�
	int i = left;
	int j = mid+1;  //i��j�Ǳ��ֳ��������ֺ����������Ŀ�ͷ�±�
	while (i <= mid && j <= right) {
		if (a[i] > a[j])
			tmp[k++] = a[j++];
		else
			tmp[k++] = a[i++];
	}
	//�������ʣ���������������е�һ��
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= right) tmp[k++] = a[j++];
	//���п���
	for (int i = left, k = 0; i <= right; i++, k++) {  //i�������l����Ϊ�Ǵ�l��ʼ������������0
		a[i] = tmp[k];
	}
}
//ʹ�÷ǵݹ���ʵ�ֹ鲢����
void mergesortnonr(int* a, int numsize) {
	/*mergesort(a, left, mid);
	mergesort(a, mid + 1, right);*/
	int gap = 1;
	while (gap < numsize) {
		for (int q = 0; q <numsize; q += 2 * gap) {
			int begin = q;//��¼һ�´�ʱ�����鿪ʼ�±�
			int i = q;
			int j= q + gap;
			int iend=q+gap-1;
			int jend = q + 2 * gap - 1;  //jend���Ǵ�ʱ����Ľ����±�
			//��Խ����������һ������
			if (iend >= numsize || j >= numsize) //iendԽ��������߽����jԽ��������߽磬������һ�����
			{
				break;
			}

			if (jend >= numsize)  //jendԽ��������߽�
			{
			  	jend = numsize - 1;   //�ֶ��������߽�����
			}
			//����һ������������������
			int tmp[1000];
			int k = 0; //k�������±�
			
			while (i <= iend && j <= jend) {
				if (a[i] > a[j])
					tmp[k++] = a[j++];
				else
					tmp[k++] = a[i++];
			}
			//�������ʣ���������������е�һ��
			while (i <= iend) tmp[k++] = a[i++];
			while (j <= jend) tmp[k++] = a[j++];
			//���п���
			for (int i =begin , k = 0; i <= jend; i++, k++) {  //i�������l����Ϊ�Ǵ�l��ʼ������������0
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