#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h> // 添加对 memset 的支持
#include<assert.h>
#include <stdbool.h>
//断言被定义为assert(expression),其原型定义在<assert.h>文件中。
//assert将检查表达式expression的值来决定是否需要终止执行程序。

//1、双链表的定义：
/*
1、数据的存储
2、一个前指针
3、一个后指针
*/
typedef int LTdataType;

typedef struct ListNode
{
    struct ListNode* prev;
    LTdataType Data;
    struct ListNode* next;
}ListNode;



//2、双链表的初始化
//双链表的初始化，不用二级指针，利用返回值
//ListNode* listNode = ListInit();
ListNode* ListInit()
{
    //创建哨兵位的头节点
    ListNode* guard = (ListNode*)malloc(sizeof(ListNode));
    if(guard == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    guard->next = guard;
    guard->prev = guard;
    //头节点初始化指向自身
    return guard;
}


//3、双向链表创建新节点
//节点的创建
ListNode* BuyListNode(LTdataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    //判空
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newnode->Data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    //暂时指向空

    return newnode;
}


//4、双向链表的打印
//打印函数的实现，就是直接遍历，定义一个phead后一个的指针，当cur!=phead时就打印Data值。cur=cur.next
void ListPrint(ListNode* phead)
{
    assert(phead != NULL);

    ListNode* cur = phead->next;
    printf("guard<=>");
    while(cur != phead)
    {
        printf("%d<=>",cur->Data);
        cur = cur->next;
    }
    printf("\n");
}


//5、双向链表的尾插
//双向链表的尾插非常简单，因为头节点prev就是尾，定义一个新节点，然后直接将新节点链接到tail节点上即可
void ListPushBack(ListNode* phead,LTdataType x)
{
    assert(phead != NULL);

    //创建节点
    ListNode* newnode = BuyListNode(x);
    ListNode* tail = phead->prev;

    //记录尾前的一个
    phead->prev = newnode;
    newnode->next = phead;
    newnode->prev = tail;
    tail->next = newnode;
}


//6、双向链表的尾删
//思路：我们需要记录尾节点的前一个，将phead的prev链接到尾节点的前一个
void ListPopBack(ListNode* phead)
{
    assert(phead != NULL);

    ListNode* tail = phead->prev;

    //记录前一个
    ListNode* prev = tail->prev;
    phead->prev = prev;
    prev->next = phead;
    free(tail);
    tail = NULL;
}


//7、双向链表的头插
void ListPushFront(ListNode* phead,LTdataType x)
{
    assert(phead != NULL);

    ListNode* newnode = BuyListNode(x);
    //记录phead的后一个
    ListNode* next = phead->next;
    phead->next = newnode;  //先把next弄好，然后弄pre
    newnode->next = next;  //先把next弄好，然后弄pre

    next->prev = newnode;
    newnode->prev = phead;

}


//8、双向链表的判空
//判断phead->next等不等于phead，如果等于为空
bool ListEmpty(ListNode* phead)
{
    assert(phead != NULL);

    return phead->next == phead;
}


//求双向链表的长度
//采用计数器遍历的方法，cur为phead的下一个，！=phead，count++
int ListSize(ListNode* phead)
{
    assert(phead);
    int count = 0;
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        count++;
        cur = cur->next;
    }
    return count;
}