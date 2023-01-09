#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x) {
    //Ϊ�������߸�λΪ0ֱ��Ϊfalse
    if (x < 0 || x % 10 == 0)
    {
        return false;
    }
    if (x == 0)
    {
        return true;
    }
    //�ж��м�λ
    int a = 1;
    while ((x / a) > 9)
    {
        a = a * 10;
    }
    while (x > 0)
    {
        int left = x / a;
        int right = x % 10;
        if (left != right)
        {
            return false;
        }
        x = (x % a) / 10;
        a = a / 100;
    }
    return true;

}
int main()
{
    bool a = isPalindrome(0);
    printf("%d", a);
}