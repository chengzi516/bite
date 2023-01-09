#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main() {
	char arr1[] = "hello,world";
	char arr2[] = { 'a','b','c' };
	char arr3[] = { 'a','b','c','\0' };
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int len3 = strlen(arr3);
	printf("%d\n", len1);
	printf("%d\n", len2);
	printf("%d\n", len3);
}