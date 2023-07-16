#define _CRT_SECURE_NO_WARNINGS 1
#include "processBar.h"
#include <windows.h>

typedef void (*callback_t)(int); // 函数指针类型,此指针指向的函数参数为int，返回值为void

// 模拟一种安装或者下载
void downLoad()
{
    int total = 1000; // 1000MB
    int curr = 0;     // 0MB
    while (curr <= total)
    {
        Sleep(100);  // 模拟下载花费的时间
        int rate = curr * 100 / total; // 更新进度
        processbar(rate); // 通过回调，展示进度
        curr += 10;     // 循环下载了一部分
    }
    printf("\n");
}

int main()
{
    printf("donwnload 1: \n");
    downLoad();
    printf("donwnload 2: \n");
    downLoad();
    printf("donwnload 3: \n");
    downLoad();
    return 0;
}