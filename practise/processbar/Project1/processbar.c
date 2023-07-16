#define _CRT_SECURE_NO_WARNINGS 1
#include "processBar.h"
#include <string.h>
#include <windows.h>  //sleep和usleep的头文件，作用是暂时休眠程序

const char* lable = "|/-\\";  //一个字符数组指针，用来实现读取进度条时搭配百分比数字的动画效果
char bar[NUM];  //定义的字符数组

#define GREEN "\033[0;32;32m"   //自定义设置部分元素颜色
#define NONE "\033[m"


void processbar(int rate)
{
    if (rate < 0 || rate > 100) return;

    int len = strlen(lable);
    printf(GREEN"[%-100s]"NONE"[%d%%][%c]\r", bar, rate, lable[rate % len]);
    fflush(stdout);
    bar[rate++] = BODY;
    if (rate < 100) bar[rate] = RIGHT;
}
