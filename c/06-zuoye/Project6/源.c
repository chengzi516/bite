#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int lengthOfLastWord(char* s) {
    int a = strlen(s) - 1;
    int length = 0;
    while (s[a] == ' ')
    {
        a = a - 1;
    }
    while (s[a] != ' ' && a>=0)
    {
        length++;
        a--;
    }
    return length;
}
int main()
{
    char a[] = "a";
    int b = lengthOfLastWord(a);
    printf("%d", b);
    return 0;
}