#include<stdio.h>
#include<string.h>
#define MaxSize 100 //定义顺序表最大长度

//伪代码
//1、线性表的静态定义
typedef struct {
    ElemType data[MaxSize];
    int length;  //当前顺序表的长度
}Sqlist;  //顺序表的类型定义


//2、线性表的静态初始化
void InitList(Sqlist &L){
    for(int i = 0; i < MaxSize; i++){
        L.data[i] = 0;  //防止“脏数据”
        L.length = 0;
    }
}


//3、线性表的插入
bool ListInsert(Sqlist &L,int i,Elemtype e){
    if(i < 1 || i > L.length){
        return false;
    }
    if(L.length > L.MaxSize){
        return false;
    }
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }

    L.data[i-1] = e;
    L.length++;
    return true;
}


//4、线性表的删除
bool ListDelete(Sqlist &L,int i,ElemType e){
    if(i < 1 || i > L.length){
        return false;
    }
    e = L.data[i-1]
    for(int j = i; j < L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}


//5、线性表按索引查找
ElemType GetElem(Sqlist L,int i){
    return L.data[i-1];
}


//6、线性表按值查找
ElemType LocateElem(Sqlist L,ElemType e){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e){
            return i+1;
        }
    }
    return 0;
}


//7、动态增长内存
void IncreaseSize(Sqlist &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}