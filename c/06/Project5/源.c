#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
#include<stdio.h>
#include<assert.h>
void my_strcpy(char* dest, char* str)
{
	assert(dest != NULL && str != NULL);
	while (*str != '\0')
	{
		*dest++ = *str++;
	}
	*dest = *str;
}
//int main()
//{
//	char ch1[] = "qqqqqq";
//	char* p = ch1;
//	//my_strcpy(ch1,p);
//	*p = 'a';
//	printf("%s", ch1);
//	//printf("%s", ch1);
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int* a = arr;
//	a[1] = 3;
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
char* longestCommonPrefix(char** strs, int strsSize) {
    int maxlen = strlen(strs[0]);
    char* num = strs[0];

    for (int j = 1; j < strsSize; j++)
    {
        int i = 0;
        while (i < maxlen && strs[j][i] == num[i])//第0行先于第1行比较然后记录多少个字节一样
        {
            i++;

        }
        maxlen = i;//把得到的数再返回给a
    }
    num[maxlen] = '\0';
    return num;
}
int main()
{
    char a[] = "flaaa";
    char b[] = "flqqq";
    char c[] = "flwww";
    char* str[] = { a,b,c };
    char* num=longestCommonPrefix(str, 3);
    printf("%s", num);

}