//队列：只允许在一端进行插入数据操作，在另一端进行删除数据操作的特殊线性表，队列具有先进先出的特性
//队尾：进行插入操作的一端
//队头：进行删除操作的一端

#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h>

#define MaxSize 256
//1、定义顺序队列存储结构
typedef struct
{
    int data[MaxSize];
    int front,rear;
}SqQueue;


//2、初始化
int InitQueue(SqQueue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    return 1;
}

//SqQueue Q;
//InitQueue(&Q)


//3、求顺序表的长度
int QueueLength(SqQueue Q)
{
    return Q.rear - Q.front;
}


//4、入队操作
int EnQueue(SqQueue* Q,int e)
{
    if(Q->rear == MaxSize)  //判断队列是否已满
    {
        return 0;
    }
    Q->data[Q->rear] = e;  //元素e复制给队尾
    Q->rear++;  //队尾指针后移
    return 1;

}


//5、出队操作
int DeQueue(SqQueue* Q,int* e)
{
    if(Q->rear == Q->front)  //队空
    {
        return 0;
    }
    *e = Q->data[Q->front];  //队头元素赋值给e
    Q->front++;  //队头指针后移
    return 1;
}

/*
缺点：使用【顺序表】实现队列有一个缺点，
队列满的时候，无法继续从队尾插入新元素，数组仍有空闲空间，造成空间浪费，
会有假溢出问题
*/

//之前的入队改为
int EnQueue(SqQueue* Q,int e)
{
    if((Q->rear+1)%MaxSize == Q->front)
    {
        return 0;
    }
    Q->data[Q->rear] = e;  //元素e赋值给队尾
    Q->rear++;  //队尾指针后移
    return 1;
}

