#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x) {
    //˼·1 ������ת��Ϊ�ַ����飬������ָ����б���
//   char arr[100];
//   sprintf(arr,"%d",x);
//   char left=0;
//   char right=strlen(arr)-1;
//   while(left<right)
//   {
//       if(arr[left]!=arr[right])
//       {
//               return false;
//       }
//       left++;
//       right--;
//   }
//   return true;
//����ѧ�Ľⷨ��ÿһλ���в�֡�
//�����޷�����0���Թ�
    if (x == 0)
        return true;
    if (x < 0)
        return false;
    //ȷ������λ��
    int tmp = x;
    int count = 1;
    while (tmp > 9)
    {
        tmp /= 10;
        count*=10;
    }//count��Ϊ��ȷ����λ����
    //ȷ��������λ��
    int left;
    int right;
    while (x > 0)
    {
        left = x / count;
        right = x % 10;
        if (left != right)
        {
            return false;
        }
        x = (x % count) / 10;
        count /= 100;
    }
    return true;

}
char* longestCommonPrefix(char** strs, int strsSize) {
    //ǰ׺�϶����ᳬ����һ�������������ָ�룬˵����һ���ַ������飬�����Ƕ���ַ����顣
    //��ȡ��һ���ַ������������жϡ�
    char* chuan = strs[0];//��chuanָ���һ���ַ����顣
    int maxlen = strlen(strs[0]);
    int sum = 0;
    for (int i = 1; i < strsSize; i++) //ȷ���ȽϵĴ����
    {
        sum = 0;
        for (int j = 0; j < maxlen; j++)
        {
            
            if (chuan[j] == strs[i][j])
            {
                sum++;
            }
            
        }
        maxlen = sum;
    }
    chuan[maxlen] = '\0';
    return chuan;
}
int main()
{
    char a[] = "dog";
    char b[] = "racecar";
    char c[] = "car";
    char* arr[] = { a,b,c };
    char* d = longestCommonPrefix(arr, 3);
    printf("%s", d);
}