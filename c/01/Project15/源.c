#define _CRT_SECURE_NO_WARNINGS 1
//�ؼ���typedef
//#include<stdio.h>
//typedef unsigned int uint;
//int main() {
//	uint a = 10;
//	return 0;
//}
//�ؼ���static
//#include<stdio.h>
//void test() {
//	static int q=0;
//	q++;
//	printf("%d\n", q);
//}
//int main() {
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		test();
//
//	}
//	return 0;
//
//}
//define���峣�����
//#include<stdio.h>
//#define A 10   //�����ʶ������
//#define sum(x,y)  ((x)+(y)) //�����
//int main() {
//	int a = sum(1, 2);
//	printf("%d", a);
//	return 0;
//}
//#include<stdio.h>
//int main() {
//	int a = 10;
//	&a;//��ȡַ��ȡ��a�ĵ�ַ
//	printf("%p", &a);  //%p���Ե�ַ��ʽ��ӡ
//	return 0;
//
//}
//
#include<stdio.h>
int main() {
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(double*));
	return 0;
}