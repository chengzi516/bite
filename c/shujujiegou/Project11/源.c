#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#define Max 100

//定义串

typedef struct String

{

    char data[Max]; //限制了串的最大长度

    int length;

}String;

//创建串的函数

void Stringcreate(String* T, char* ch)

{

    int i = 0;

    for (; ch[i] != '\0'; i++)

    {

        T->data[i] = ch[i];

    }

    T->length = i;//i最好放在循环外部，否则会因为作用域原因找不到i

}



void shuchu(String s)

{

    int i;

    if (s.length > 0)

    {

        for (i = 0; i < s.length; i++)

            printf("%c", s.data[i]);

        printf("\n");

    }

}



String jiami(String A, String B, String C)

{

    int i = 0;

    int j = 0;

    //创建一个加密串

    String str;

    for (i = 0; i < C.length; i++)

    {

        str.data[i] = B.data[j];

        j++;

    }

    str.length = C.length;

    return str;

}



String jiemi(String A, String B, String C)//输入字母映射表和要解密的串

{

    int i = 0;

    int j = 0;

    String str;

    for (i = 0; i < C.length; i++)

    {

        str.data[i] = A.data[j];

        j++;

    }

    str.length = C.length;

    return str;

}



int main()

{

    String A, B, C, S1, S2;

    //创建了两个串分别存储加密信息

    Stringcreate(&A, "abcdefghijklmnopqrstuvwxyz");

    Stringcreate(&B, "ngzqtcobmuhelkpdawxfyivrsj");

    //将要进行加密的串单独创建一个

    char str[Max];

    printf("输入要加密信息");

    gets(str);

    Stringcreate(&C, str);

    //将串进行加密

    S1 = jiami(A, B, C);

    printf("加密");

    shuchu(S1);

    //将串进行解密

    printf("解密");

    S2 = jiemi(A, B, S1);

    shuchu(S2);

}

