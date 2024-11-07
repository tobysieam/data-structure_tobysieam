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

// 4、判断队列是否为空
// 判断q->front == NULL && q->rear == NULL的条件成立即可
int QueueEmpty(LinkQueue *q)
{
    if (q->front == NULL && q->rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 5、入队
void enQueue(LinkQueue *q, ElemType e)
{
    DataNode *t;
    // 构造一个节点t，data域存储e，next域存储NULL
    t = (DataNode *)malloc(sizeof(DataNode));
    t->data = e;
    t->next = NULL;
    // 添加
    if (q->front != NULL || q->rear != NULL)
    {
        // 队非空
        q->rear->next = t;
        q->rear = t;
    }
    else
    {
        // 队空
        q->front = t;
        q->rear = t;
    }
}

// 6、出队
/*
若队列非空，出队，返回1，否则，提示，返回0
*/
int deQueue(LinkQueue *q, ElemType *e)
{
    DataNode *t;

    if (q->front != NULL || q->rear != NULL) // 非空
    {
        // 1、让t指向队头元素节点
        t = q->front;
        // 2、把队头元素存储到e
        *e = t->data;
        // 3、删除队头元素节点
        if (q->front->next == NULL) // 只有1个元素
        {
            // 只有一个元素
            q->front = NULL;
            q->rear = NULL;
        }
        else
        {
            // 多于一个元素
            q->front = t->next;
        }
        // 4、释放t所占的内存空间
        free(t);
        return 1;
    }
    else
    {
        printf("队空，不能出队\n");
        return 0;
    }
}

// 7、求队列长度
int lengthLinkQueue(LinkQueue *q)
{
    int len;
    if (QueueEmpty(&q)) // 判断队列是否为空
    {
        len = 0;
        return len;
    }

    DataNode *t;
    // 构造一个节点t，让它指向队首元素front
    t = (DataNode *)malloc(sizeof(DataNode));
    t = q->front;
    len = 1;
    while (t->next != NULL)
    {
        len++;
        t = t->next;
    }
    printf("队列长度为%d\n", len);
}

// 8、打印队列中的元素
void DispQueue(LinkQueue *q)
{
    DataNode *p;
    p = q->front;
    printf("队列元素为：");
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

// 9、销毁队列
void DestroyQueue(LinkQueue *q)
{
    int deQueue(LinkQueue * q, ElemType * e);
    ElemType m;

    while (q->front != NULL || q->rear != NULL)
    {
        // 出队
        deQueue(q, &m);
    }
    free(q);
}

// 测试代码
int main()
{
    LinkQueue lq = *InitQueue();
    enQueue(&lq, 1);
    enQueue(&lq, 2);
    enQueue(&lq, 3);
    enQueue(&lq, 4);
    enQueue(&lq, 5);
    enQueue(&lq, 6);
    enQueue(&lq, 7);
    enQueue(&lq, 8);
    enQueue(&lq, 9);
    DispQueue(&lq);
    lengtthLinkQueue(&lq);

    ElemType *e;
    e = (ElemType *)malloc(sizeof(ElemType));
    deQueue(&lq, e);
    printf("出队元素：‰d\n", *e);
    deQueue(&lq, e);
    printf("出队元素：%d\n", *e);
    printf("队列为空返回1，否则返回0：%dn", QueueEmpty(&lq));
    DispQueue(&lq);
    lengthLinkQueue(&lq);
    DestroyQueue(&lq); // 销毁队列
    return 1;
}
