#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h> 

//1、单链表的定义
typedef struct node_t  //把结构体类型重定义为LinkNode_t
{
    int data;
    struct node_t *next;
}LinkNode_t;

/*
功能：创建一个链表的头节点（堆空间）
返回值：头节点的地址   
*/
LinkNode_t *createLinkList(){  //为简化程序，本程序没有做申请空间失败的检查
    LinkNode_t* node = (LinkNode_t*)malloc(sizeof(LinkNode_t));
    node->next = NULL;  //最后一个节点的next一定指向NULL
    return node;  //返回指向头节点的指针
}
//调用上述函数时，LinkNode_t* head = createLinkList(); 
//此时我们便创建了一个单向链表，函数返回的节点指针是这个链表的头节点，这个节点我们不存储数据，此时链表志愿一个节点即head


//2、判断链表是否为空
/*
功能：判断链表是否为空
参数：链表的头节点指针
返回值：空返回1，非空返回0
*/
int emptyLinkList(LinkNode_t* p)
{
    return p->next == NULL;
}


//3、计算链表中除空头节点之外的节点个数
/*
功能：计算链表中除空头节点之外的节点个数
参数：链表头节点指针
返回值：节点个数
*/
int lengthLinkList(LinkNode_t* p)
{
    int count = 0;
    LinkNode_t* t = p->next;  //不能直接用head作为判断条件
    while(t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}


//4、插入新节点
/*
功能：在链表中插入新节点并存入数据
参数1：链表头节点指针
参数2：插入的位置（第一个有数据的节点位置为0）
参数3：新节点的值
返回值：成功返回0，失败返回1
*/
int insertLinkList(LinkNode_t* p,int pos,int x)
{
    if(pos < 0||pos > lengthLinkList(p))  //对pos做合法性检查
    {
        return -1;
    }
    //构建一个新的节点，并赋值
    LinkNode_t*newNode = (LinkNode_t*)malloc(sizeof(LinkNode_t));
    newNode->data = x;  //赋值
    newNode->next = NULL;  //暂时指向NULL

    LinkNode_t* t = p;
    int i;
    for(i = 0; i < pos; i++)
    {
        t = t->next;
    }
    //将节点插入链表
    newNode->next = t->next;
    t->next = newNode;
    return 0;
}


//5、获取某位置节点的值
/*
功能：获取链表中某节点的值
参数1：链表头节点指针
参数2：位置（第一个有数据的节点位置为0）
返回值：失败返回-1，成功返回参数2位置节点的值
*/
int getLinkList(LinkNode_t* p,int pos)
{
    if(pos < 0||pos > lengthLinkList(p))
    {
        return -1;
    }
    int i;
    LinkNode_t* t = p->next;
    for(i = 0; i < pos; i++)
    {
        t = t->next;
    }
    return t->data;
}


//6、遍历输出链表中所有节点的值
/*
功能：遍历输出链表中节点的值
参数：链表头节点指针
无返回值
*/
void printLinkList(LinkNode_t* p)
{
    printf("\n有效数据节点数:%d\n",lengthLinkList(p));
    int count = 0;
    LinkNode_t* t = p->next;
    while (t != NULL)
    {
        printf("NODE[%d]:%d\n",count,t->data);
        t = t->next;
        count++;
    }
    
}


//7、删除链表中的节点
/*
功能：删除参数位置节点
参数1：链表头节点指针
参数2：删除位置
返回值：失败返回-1，成功返回0
*/
int deleteLinkList(LinkNode_t* p,int pos)
{
    if(pos < 0||pos >= lengthLinkList(p))
    {
        return -1;
    }

    int i;
    LinkNode_t* t = p;  //指向空头节点
    for(i = 0; i < pos; i++)//循环结束得到待删除节点的前一个节点的位置
    {
        t = t->next;
    }
    LinkNode_t* s = t->next;//保存要删除节点的地址
    t->next = t->next->next;
    free(s);
    return 0;

}


//8、清空链表
/*
功能：清空链表
参数：链表头节点指针
*/
void clearLinkList(LinkNode_t* p)
{
    while(p != NULL)
    {
        LinkNode_t* t = p;
        p = p->next;
        free(t); 
    }
}

int main()
{
LinkNode_t*head = createLinkList();
insertLinkList(head,0,10);//10
insertLinkList(head,0,20);//20 10
insertLinkList(head,1,30);//20 30 10
insertLinkList(head,3,40);//20 30 10
printLinkList(head);//20 30 10 40
insertLinkList(head,4,50);//20-30 10 40 50
printf("\n%d\n",getLinkList(head,0));//20
deleteLinkList(head,0);//30 10 40 50
printLinkList(head);
return 0;
}