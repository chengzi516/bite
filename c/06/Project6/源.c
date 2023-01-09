#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x) {
    //思路1 将数字转换为字符数组，用左右指针进行遍历
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
//用数学的解法将每一位进行拆分。
//负数无法过，0可以过
    if (x == 0)
        return true;
    if (x < 0)
        return false;
    //确定数的位数
    int tmp = x;
    int count = 1;
    while (tmp > 9)
    {
        tmp /= 10;
        count*=10;
    }//count即为所确定的位数。
    //确定左右两位数
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
    //前缀肯定不会超过第一个串。传入二级指针，说明是一个字符串数组，里面是多个字符数组。
    //先取第一个字符串出来进行判断。
    char* chuan = strs[0];//让chuan指向第一个字符数组。
    int maxlen = strlen(strs[0]);
    int sum = 0;
    for (int i = 1; i < strsSize; i++) //确定比较的大次数
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