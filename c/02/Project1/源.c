#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	////����֧
	//if (���ʽ)  
	//	���;
	////˫��֧
	//if (���ʽ)  
	//	���;
	//else
	//	���;
	////���֧
	//if (���ʽ) 
	//	���;
	//else if(���ʽ)
	//	���;
	//else
	//	���;
	//01
	//int age = 15;
	//if (age < 18) {
	//	printf("δ����");
	//}
	//02
	//int age = 19;
	//if (age < 18) {
	//	printf("δ����");
	//}
	//else {
	//	printf("����");
	//}
	//03
	/*int age = 77;
	if (age < 18) {
		printf("δ����");
	}
	else if (age >= 18 && age < 30) {
		printf("����");
	}
	else if (age >= 30 && age < 50) {
		printf("����");
	}
	else if (age >= 50 && age < 120) {
		printf("����");
	}
	else
	{
		printf("������ȷ���� ");
	}*/

	//04

		//int a = 0;
		//int b = 0;
		//if (a == 1)
		//	if (b == 2)
		//		printf("1");
		//else
		//		printf("2");
	//05
	/*int true = 1;
	if (true) {
		return 1;
	}
	else {
		return 2;
	}*/
	//06
	/*int day = 0;
	scanf("%d", &day);
	switch (day) {
	case 1:
		printf("monday\n");
		break;
	case 2:
		printf("tuesday\n");
		break;
	case 3:
		printf("wednesday\n");
		break;
	case 4:
		printf("thursday\n");
		break;
	case 5:
		printf("friday\n");
		break;
	case 6:
		printf("saturday\n");
		break;
	case 7:
		printf("sunday\n");
		break;
	default:
		printf("error\n");
		break;

	}*/
	//
	/*int day = 0;
	scanf("%d", &day);
	switch (day) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");


	}*/

int n = 1;
int m = 2;
switch (n) {
case 1:
	m++;
case 2:
	n++;
case 3:
	switch (n) {
	case 1:
		n++;
	case 2:
		m++;
		n++;
		break;
	}
case 4:
	m++;
	break;
default:
	break;
}
printf("m=%d,n=%d", m, n);


	return 0;
}