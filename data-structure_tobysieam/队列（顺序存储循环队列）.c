//解决假溢出问题
/*
同时舍弃一个空间，因为之前我们判断队列为空的条件是：rear == front,
在循环队列的中，这种情况也可能会将已经满了的队列判断为空队列
所以，当队列还剩一个空间时就判断队列已满
假定队列最大元素个数为maxsize，判满条件为：(rear+1)%maxsize == front
*/

//总结：队列判空和判满的条件分别是：
/*
对列为空：rear == front
队列为满：(rear+1)%maxsize == front
*/


//之前的入队改为
/*int EnQueue(SqQueue* Q,int e)
{
    if((Q->rear+1)%MaxSize == Q->front)
    {
        return 0;
    }
    Q->data[Q->rear] = e;  //元素e赋值给队尾
    Q->rear++;  //队尾指针后移
    return 1;
}

*/