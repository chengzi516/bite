#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	//为a开辟了一块空间存储了10，使用了取址操作符取出了a的第一个字节地址，并存到了p中
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int* pi = &n;
//	char* pc = (char*)&n;//必须要强制类型转换，否则会有警告或报错 
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