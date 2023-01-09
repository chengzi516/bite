#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));
//}
//
//int main()
//{
//	
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(ch));
//	test1(arr);
//	test2(ch);
//
//}
//int main()
//{
//	int x = 10;
//	printf("%d\n", --x);
//	printf("%d\n", x--);
//	printf("%d\n", ++x);
//	printf("%d\n", x++);
//	printf("%d", x);
////}
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ || ++b || d++;
//	printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);
//}
//int main()
//{
//	int a = 5;
//	int b = 3;
//	int c = (a > b) ? a : b;
//	printf("%d", c);
//}
//int main()
//{
//	int arr[10];
//	arr[2] = 20;
//}
struct stu
{
	char name[10];
	int age;
	char sex[10];
};
void test(struct stu* p)
{
	p->age = 12;
}
int main()
{
	struct stu Stu1;
	Stu1.age = 10;
	struct stu Stu2;
	struct stu* p = &Stu2;
	test(p);
}