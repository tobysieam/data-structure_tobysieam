#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h> 
# define STACK_INIT_SIZE 100
/*
1、栈也是一种线性结构，不过它比较特殊，它的特点是：先进先出，后进先出
2、在栈顶插入元素称为入栈，在栈顶删除元素称为出栈
3、这里我们选用数组来模拟栈
4、由于栈在使用的过程中所需要的大小难以估计，所以通常是先为栈分配一个基本容量，
然后在使用的过程中，当栈的空间不够使用的时候再继续追加存储空间
*/

typedef int SDataType;

//1、栈的定义
typedef struct{
    SDataType* base;  //栈底指针
    SDataType* top;   //栈顶指针
    int StackSize;  //当前已经分配的存储空间，以元素为单位
}SqStack;
//s.base == s.top 可作为栈空的标记


//2、初始化栈
//top为栈顶指针，top的初值指向栈底
//每当插入一个元素时top加1，弹出一个元素时top减1
//初始化顺序栈，构造一个空栈
int InitStack(SqStack S){
    //分配存储空间
    S.base = (SDataType*)malloc(STACK_INIT_SIZE*sizeof(SDataType));
    if(!S.base){
        //如果分配失败，则返回0
        return 0;
    }
    //S.top始终指向栈顶元素的下一个位置
    S.top = S.base;  //初始状态下为空栈
    S.StackSize = STACK_INIT_SIZE;  //当前已经分配的存储容量为100个
}


//3、判断是否为空栈
void judgeNull(SqStack s)
{
    if(s.top == s.base)
    {
        printf("此栈为空栈\n");
    }
    else{
        printf("此栈不为空栈\n");
    }
}


//4、判断是否为满栈
void judgeFull(SqStack s)
{
    if(s.top-s.base == s.StackSize)
    {
        printf("栈满\n");
    }
    else
    {
        printf("栈未满\n");
    }
}


//5、入栈
//入栈时我们首先要判断栈是否为满栈，如果为满栈我们要首先追加存储空间
//分配一个大小为new_size字节的新内存块，并复制大小等于新旧大小中较小者的内存区域，然后释放旧内存块
//void* realloc(void* ptr,new_size)
int Push(SqStack s,SDataType e)
{
    SDataType* p;
    //首先判断栈是不是满的（上溢）
    if(s.top-s.base == s.StackSize)
    {
        //追加空间
        p = (SDataType*)realloc(s.base,(s.StackSize+STACKINCREMENT)*sizeof(SDataType));
        if(!p)
        {
            //如果没有找到符合条件的存储空间，则返回0
            return 0;
        }

        //成功找到则使s.base指向p
        s.base = p;
        s.top = s.base + s.StackSize;
        s.StackSize += STACKINCREMENT; 
    }
    //先插入元素，然后将栈顶指针加1
    *(s.top) = e;
    s.top++;
    return 1;
}


//6、出栈
//出栈时我们首先要判断栈是否为空栈。如果栈已经空了，则返回0
int Pop(SqStack s,SDataType e)
{
    //判断是否会发生下溢
    if(s.top != s.base){
        s.top--;  //先将栈顶指针减1
        e = *(s.top);
    }
    else{
        return 0;
    }
    return e;
}