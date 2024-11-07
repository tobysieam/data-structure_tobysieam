/*
在链队中只允许单链表的表头进行删除操作（出队），表尾进行插入操作（入队）
分为头结点和普通节点
*/
#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h>

// 1、数据结点类型DataNode
typedef int ElemType;
// 值节点--多个
typedef struct Node
{
    ElemType data;     // 存储队列的元素值
    struct Node *next; // 存储下一个元素节点的地址
} DataNode;

// 链队头节点类型
typedef struct
{
    DataNode *front; // 存储队头元素节点的地址(队首指针)
    DataNode *rear;  // 存储队尾元素节点的地址(队尾指针)

} LinkQueue;


// 3、链队初始化
// 构造一个空的队列，既创建一个链队结点，将front和rear域都设置为NULL
LinkQueue *InitQueue()
{
    LinkQueue *q;
    q = (LinkQueue *)malloc(sizeof(LinkQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
// LinkQueue lq = *InitQueue();


//4、判断队列是否为空
//判断q->front == NULL && q->rear == NULL的条件成立即可
int QueueEmpty(LinkQueue* q)
{
    if(q->front == NULL && q->rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//5、入队
void enQueue(LinkQueue* q,ElemType e)
{
    DataNode* t;
    //构造一个节点t，data域存储e，next域存储NULL
    t = (DataNode*)malloc(sizeof(DataNode));
    t->data = e;
    t->next = NULL;
    //添加
    if(q->front != NULL||q->rear != NULL)
    {
        //队非空
        q->rear->next = t;
        q->rear = t;
    }
    else
    {
        //队空
        q->front = t;
        q->rear = t;
    }
}