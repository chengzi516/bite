#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType elem[MaxSize];
    int length;
} SqList;

// ��ʼ�����Ա�
void InitList(SqList* L) {
    L->length = 0;
}

// ��ȡ���Ա�ĳ���
int GetLen(SqList L) {
    return L.length;
}

// �ж����Ա��Ƿ�Ϊ��
int ListEmpty(SqList L) {
    return L.length == 0;
}

// ��ȡ���Ա���ָ��λ�õ�Ԫ��
int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length)
        return 0;
    return L.elem[i - 1];
}

// ����ָ��Ԫ�������Ա��е�λ��
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

// �����Ա��ָ��λ�ò���Ԫ��
int ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1)
        return 0;
    i--; /* ��λ��ת��Ϊ�����±� */
    for (int j = L->length; j > i; j--) /* ��Ԫ�غ���һ��λ�� */
        L->elem[j] = L->elem[j - 1];
    L->elem[i] = e;
    L->length++; /* ���Ա�����1 */
    return 1;
}

// ɾ�����Ա���ָ��λ�õ�Ԫ��
int ListDelete(SqList* L, int i, ElemType* e) {
    if (i < 1 || i > L->length)
        return 0;
    i--; /* ��λ��ת��Ϊ�����±� */
    *e = L->elem[i]; /* ��ȡҪɾ����Ԫ�� */
    for (int j = i; j < L->length - 1; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return 1;
}

// ������ B �ϲ������� A �У�ȷ��Ԫ�ز��ظ�
void Union(SqList* A, SqList B) {
    for (int i = 0; i < B.length; i++) {
        ElemType e = B.elem[i];
        if (!LocateElem(*A, e))
            ListInsert(A, A->length + 1, e);
    }
}

// ���㼯�� A �ͼ��� B �Ľ���������洢�ڼ��� C ��
void Intersection(SqList A, SqList B, SqList* C) {
    InitList(C); /* ��ʼ�� C */
    for (int i = 0; i < B.length; i++) {
        ElemType e = B.elem[i];
        if (LocateElem(A, e))
            ListInsert(C, C->length + 1, e);
    }
}

// ���㼯�� A �ͼ��� B �Ĳ��A - B��
void Difference(SqList* A, SqList B) {
    for (int i = 0; i < B.length; i++) {
        ElemType e = B.elem[i];
        int pos = LocateElem(*A, e);
        if (pos)
            ListDelete(A, pos, &e);
    }
}

// ��ӡ���Ա��Ԫ��
void PrintList(SqList L) {
    printf("{ ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("}\n");
}

int main() {
    SqList A, B, T, C;

    InitList(&A);
    InitList(&B);
    InitList(&T);
    InitList(&C);

    printf("���뼯�� A ��Ԫ�أ��� 0 ����:\n");
    ElemType x;
    scanf("%d", &x);
    while (x != 0) {
        ListInsert(&A, 1, x);
        scanf("%d", &x);
    }

    printf("���뼯�� B ��Ԫ�أ��� 0 ����:\n");
    scanf("%d", &x);
    while (x != 0) {
        ListInsert(&B, 1, x);
        scanf("%d", &x);
    }

    Union(&T, B);
    printf("���� A �ͼ��� B �Ĳ���: ");
    PrintList(T);

    Intersection(A, B, &C);
    printf("���� A �ͼ��� B �Ľ���: ");
    PrintList(C);

    Difference(&A, B);
    printf("���� A ��ȥ���� B �Ĳ (A - B): ");
    PrintList(A);

    return 0;
}
