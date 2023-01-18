#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main() {
//    int a;
//    scanf("%d", &a);
//    int flag = 1;
//    int x = 1;
//    int sum = 1;
//    int b = 1;
//    int flag2 = 0;
//    if (a == 1)
//    {
//        printf("1");
//        return 0;
//    }
//    while (flag)
//    {
//        if (flag2 )
//        {
//            b += 2;
//            sum = b;
//            x = b;
//         }
//        flag2++;
//        for (int i = 1; i < a; i++)
//        {
//            sum += x + 2;
//            x += 2;
//        }
//
//        if (sum == (a * a * a))
//            flag--;
//    }
//    for (int i = a-1; i > 0; i--)
//    {
//        printf("%d+", x - (i * 2));
//    }
//    printf("%d", x);
//}

int main()
{
   /* int n, a1 = 2;
    while (~scanf("%d", &n)) {
        int an = a1 + (n - 1) * 3
        printf("%d\n", n * (a1 + an) / 2); 
    } 
    return 0;*/

    int a[5] = { 1,2,3,4,5 };
    int* ptr = (int*)(&a + 1);
    printf("%d,%d", *(a + 1), *(ptr - 1));
    return 0;
}