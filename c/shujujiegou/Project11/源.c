#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#define Max 100

//���崮

typedef struct String

{

    char data[Max]; //�����˴�����󳤶�

    int length;

}String;

//�������ĺ���

void Stringcreate(String* T, char* ch)

{

    int i = 0;

    for (; ch[i] != '\0'; i++)

    {

        T->data[i] = ch[i];

    }

    T->length = i;//i��÷���ѭ���ⲿ���������Ϊ������ԭ���Ҳ���i

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

    //����һ�����ܴ�

    String str;

    for (i = 0; i < C.length; i++)

    {

        str.data[i] = B.data[j];

        j++;

    }

    str.length = C.length;

    return str;

}



String jiemi(String A, String B, String C)//������ĸӳ����Ҫ���ܵĴ�

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

    //�������������ֱ�洢������Ϣ

    Stringcreate(&A, "abcdefghijklmnopqrstuvwxyz");

    Stringcreate(&B, "ngzqtcobmuhelkpdawxfyivrsj");

    //��Ҫ���м��ܵĴ���������һ��

    char str[Max];

    printf("����Ҫ������Ϣ");

    gets(str);

    Stringcreate(&C, str);

    //�������м���

    S1 = jiami(A, B, C);

    printf("����");

    shuchu(S1);

    //�������н���

    printf("����");

    S2 = jiemi(A, B, S1);

    shuchu(S2);

}

