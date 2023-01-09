#define _CRT_SECURE_NO_WARNINGS 1
////01
//#include<stdio.h>
//    int sum(int a)
//    {
//        int c = 0;
//        static int b = 3;
//        c += 1;
//        b += 2;
//        return (a + b + c);
//    }
//    int main()
//    {
//        int i;
//        int a = 2;
//        for (i = 0; i < 5; i++)
//        {
//            printf("%d,", sum(a));
//        }
//        return 0;
//    }
//02
//
//#include <stdio.h>
//
//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < 5; i++)
//    {
//        float score = 0.0;
//        float sum = 0.0;
//        for (j = 0; j < 5; j++)
//        {
//            scanf("%f", &score);
//            sum += score;
//            printf("%.1f ", score);
//        }
//        printf("%.1f\n", sum);
//    }
//    return 0;
//}
//
// 03
//#include <stdio.h>
//
//int main()
//{
//    float arr[5][6];
//    for (int i = 0; i < 5; i++) {
//        float sum = 0;
//        for (int j = 0; j < 5; j++) {
//            scanf("%f", &arr[i][j]);
//            sum += arr[i][j];
//        }
//        arr[i][5] = sum;
//    }
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 6; j++) {
//            printf("%.1f ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
// 
// 04
//#include <stdio.h>
//
//int main() {
//    int a;
//    while ((scanf("%d", &a)) != EOF) {
//        for (int i = 0; i < a; i++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
// 
//05
//#include <stdio.h>
//
//int main() {
//    int second;
//    scanf("%d", &second);
//    printf("%d %d %d", second / 3600, (second % 3600) / 60, (second % 3600) % 60);
//    return 0;
//}
