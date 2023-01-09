#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int romanToInt(char* s) {
    int flag1 = 0;
    int sum = 0;
    int flag2 = 0;
    int strLength = strlen(s);
    for (strLength-1; strLength >= 0; --strLength) {
        switch (*(s + strLength)) {
        case 'I': flag1 = 1;
            break;
        case 'V': flag1 = 5;
            break;
        case 'X': flag1 = 10;
            break;
        case 'L': flag1 = 50;
            break;
        case 'C': flag1 = 100;
            break;
        case 'D': flag1 = 500;
            break;
        case 'M': flag1 = 1000;
            break;
        }
        flag2 = flag2 > flag1 ? -flag1 : flag1;
        sum += flag2;
    }
    return sum;
}
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
        maxlen= i;//把得到的数再返回给a
    } 
    char arr[3000]={0};
    for (int j = 0; j < maxlen; j++)
    {
        arr[j] = num[j];
    }

    arr[maxlen] = '\0';
    return arr;

}
int main()
{
    char* strs[] = { "flower", "flow", "flight" };
    char* arr = longestCommonPrefix(strs, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%c", arr[i]);
    }
    

}