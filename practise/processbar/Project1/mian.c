#define _CRT_SECURE_NO_WARNINGS 1
#include "processBar.h"
#include <windows.h>

typedef void (*callback_t)(int); // ����ָ������,��ָ��ָ��ĺ�������Ϊint������ֵΪvoid

// ģ��һ�ְ�װ��������
void downLoad()
{
    int total = 1000; // 1000MB
    int curr = 0;     // 0MB
    while (curr <= total)
    {
        Sleep(100);  // ģ�����ػ��ѵ�ʱ��
        int rate = curr * 100 / total; // ���½���
        processbar(rate); // ͨ���ص���չʾ����
        curr += 10;     // ѭ��������һ����
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