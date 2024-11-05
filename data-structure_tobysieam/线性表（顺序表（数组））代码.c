#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h> // 添加对 memset 的支持

#define MaxSize 100 // 定义顺序表最大长度

// 线性表的静态定义
typedef struct {
    int data[MaxSize];
    int length;  // 当前顺序表的长度
} Sqlist;  // 顺序表的类型定义

// 线性表的静态初始化
void InitList(Sqlist *L) {
    memset(L->data, 0, sizeof(L->data)); // 防止“脏数据”
    L->length = 0;
}

// 线性表的插入
int ListInsert(Sqlist *L, int i, int e) {
    if (i < 1 || i > L->length + 1 || L->length >= MaxSize) {
        return 0; // 插入失败
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return 1; // 插入成功
}

// 线性表的删除
int ListDelete(Sqlist *L, int i, int *e) {
    if (i < 1 || i > L->length) {
        return 0; // 删除失败
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return 1; // 删除成功
}

// 线性表按索引查找
int GetElem(Sqlist L, int i) {
    if (i < 1 || i > L.length) {
        return -1; // 索引超出范围
    }
    return L.data[i - 1];
}

// 线性表按值查找
int LocateElem(Sqlist L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

// 动态增长内存
void IncreaseSize(Sqlist *L, int len) {
    int *p = L->data;
    L->data = (int *)malloc((MaxSize + len) * sizeof(int));
    if (L->data == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i];
    }
    L->length = L->length; // 这里不需要重新赋值
    MaxSize += len; // 这里应该定义为全局变量或者传递参数
    free(p);
}

int main() {
    Sqlist L;
    InitList(&L);
    int e;
    int success;

    // 测试插入操作
    success = ListInsert(&L, 1, 10);
    printf("插入元素 10 成功：%d\n", success);
    success = ListInsert(&L, 2, 20);
    printf("插入元素 20 成功：%d\n", success);

    // 测试删除操作
    success = ListDelete(&L, 1, &e);
    printf("删除元素成功：%d，删除的元素是：%d\n", success, e);

    // 测试按索引查找
    e = GetElem(L, 1);
    printf("索引 1 处的元素是：%d\n", e);

    // 测试按值查找
    int pos = LocateElem(L, 20);
    printf("元素 20 的位置是：%d\n", pos);

    // 测试动态增长内存
    IncreaseSize(&L, 50);
    printf("顺序表内存已增加。\n");

    return 0;
}