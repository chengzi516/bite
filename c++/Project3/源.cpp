#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType elem[MaxSize];
    int length;
} SqList;

// 初始化线性表
void InitList(SqList* L) {
    L->length = 0;
}

// 获取线性表的长度
int GetLen(SqList L) {
    return L.length;
}

// 判断线性表是否为空
int ListEmpty(SqList L) {
    return L.length == 0;
}

// 获取线性表中指定位置的元素
int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length)
        return 0;
    return L.elem[i - 1];
}

// 查找指定元素在线性表中的位置
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

// 在线性表的指定位置插入元素
int ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1)
        return 0;
    i--; /* 将位序转化为数组下标 */
    for (int j = L->length; j > i; j--) /* 将元素后移一个位置 */
        L->elem[j] = L->elem[j - 1];
    L->elem[i] = e;
    L->length++; /* 线性表长度增1 */
    return 1;
}

// 删除线性表中指定位置的元素
int ListDelete(SqList* L, int i, ElemType* e) {
    if (i < 1 || i > L->length)
        return 0;
    i--; /* 将位序转化为数组下标 */
    *e = L->elem[i]; /* 获取要删除的元素 */
    for (int j = i; j < L->length - 1; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return 1;
}

// 将集合 B 合并到集合 A 中，确保元素不重复
void Union(SqList* A, SqList B) {
    for (int i = 0; i < B.length; i++) {
        ElemType e = B.elem[i];
        if (!LocateElem(*A, e))
            ListInsert(A, A->length + 1, e);
    }
}

// 计算集合 A 和集合 B 的交集，结果存储在集合 C 中
void Intersection(SqList A, SqList B, SqList* C) {
    InitList(C); /* 初始化 C */
    for (int i = 0; i < B.length; i++) {
        ElemType e = B.elem[i];
        if (LocateElem(A, e))
            ListInsert(C, C->length + 1, e);
    }
}

// 计算集合 A 和集合 B 的差集（A - B）
void Difference(SqList* A, SqList B) {
    for (int i = 0; i < B.length; i++) {
        ElemType e = B.elem[i];
        int pos = LocateElem(*A, e);
        if (pos)
            ListDelete(A, pos, &e);
    }
}

// 打印线性表的元素
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

    printf("输入集合 A 的元素，以 0 结束:\n");
    ElemType x;
    scanf("%d", &x);
    while (x != 0) {
        ListInsert(&A, 1, x);
        scanf("%d", &x);
    }

    printf("输入集合 B 的元素，以 0 结束:\n");
    scanf("%d", &x);
    while (x != 0) {
        ListInsert(&B, 1, x);
        scanf("%d", &x);
    }

    Union(&T, B);
    printf("集合 A 和集合 B 的并集: ");
    PrintList(T);

    Intersection(A, B, &C);
    printf("集合 A 和集合 B 的交集: ");
    PrintList(C);

    Difference(&A, B);
    printf("集合 A 减去集合 B 的差集 (A - B): ");
    PrintList(A);

    return 0;
}
