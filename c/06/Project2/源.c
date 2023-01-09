#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//}
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	int b[] = { 5,6,7,8 };
//	int c[] = { 9,10,11,12 };
//	int* arr[3] = { a,b,c };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//}
//struct person
//{
//	char name[20];
//	char sex[10];
//	int age;
//	char position[20];
//};
//int main()
//{
//	struct person p1 = { "taylor","female",18,"singer" };
//	struct score
//	{
//		int math;
//		int chinese;
//	};
//	struct stu
//	{
//		int age;
//		char name[20];
//		struct score s;
//	};
//	struct stu p = { 12,"taylor",{78,89} };
//	struct stu q;
//	q.age = 12;
//	strcpy(q.name, "taylor");
//
//	
//}
struct stu {
	int age;
	char name[20];
};
void print(struct stu s)
{
	printf("name:%s,age:%d", s.name, s.age);
}
int main()
{
	struct stu s = { 30,"taylorswift"};
	print(s);
}