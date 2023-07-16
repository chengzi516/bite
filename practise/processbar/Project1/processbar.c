#define _CRT_SECURE_NO_WARNINGS 1
#include "processBar.h"
#include <string.h>
#include <windows.h>  //sleep��usleep��ͷ�ļ�����������ʱ���߳���

const char* lable = "|/-\\";  //һ���ַ�����ָ�룬����ʵ�ֶ�ȡ������ʱ����ٷֱ����ֵĶ���Ч��
char bar[NUM];  //������ַ�����

#define GREEN "\033[0;32;32m"   //�Զ������ò���Ԫ����ɫ
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
