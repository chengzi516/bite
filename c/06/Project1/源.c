#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	//Ϊa������һ��ռ�洢��10��ʹ����ȡַ������ȡ����a�ĵ�һ���ֽڵ�ַ�����浽��p��
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int* pi = &n;
//	char* pc = (char*)&n;//����Ҫǿ������ת����������о���򱨴� 
//	printf("%p\n", &n);
//	printf("%p\n", pi);
//	printf("%p\n", pi+1);
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//	return 0;
//
//}
//int main()
//{
//	int n = 0x12345678;
//	int* pi = &n;
//	char* pc = (char*)&n;
//	*pc = 0;
//	*pi = 0;
//	return 0;
//
//}
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p = arr;
//	for (int i = 0; i < 6; i++)
//	{
//		*(p++) = i;
//	}
//}
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("you're wrong!\n");
//	printf("%d", *p);
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d", &arr[9] - &arr[0]);
//}
//int main()
//{
//	char s[] = "abcdef";
//	char* p1 = s;
//	char* p2 = s;
//	while (*p2 != '\0')
//	{
//		p2++;
//	 }
//	printf("%d", p2 - p1);
//}
for (p = &arr[5]; p >= &arr[0]; p--)
{
	*p = 0;
}