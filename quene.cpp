#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "stack.hpp"
#include "yy.hpp"

int queue_size;

void Initqueue(Queue &Q)
{
    Q.front=0;
    Q.rear=0;
}

bool EmptyQueue(Queue Q)
{
    if (Q.front==Q.rear)
       return true;
    else 
       return false;
}

bool FullQueue(Queue Q)//循环队列判满
{
    if ((Q.rear+1)%MAXSIZE==Q.front)//牺牲一个存储单元以区分判空
       return true;
    else 
       return false;
}

bool InQueue(Queue &Q, int e)
{
    if(FullQueue(Q))
    return false;
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;

}

bool OutQueue(Queue &Q, int &e)//循环队列出队
{
    if(EmptyQueue(Q))
    return false;
    e=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;//如果仅读出队投元素，不移动对头指针

    
}

void Initqueue(QueueLink &Q)//链表实现队列初始化
{
    Q.front=Q.rear=(Lnode*)malloc(sizeof(Lnode));//申请内存储存结点，队头队尾指针指向同一结点
    Q.front->next=NULL;//包含链头
}

void InQueue(QueueLink &Q,int e)//链表实现队列入队
{
    Lnode *s=(Lnode*)malloc(sizeof(Lnode));
    s->next=Q.rear->next;//新加结点next指针指向NULL
    s->data=e;
    Q.rear->next=s;//原始队尾结点next指针指向新加结点
    Q.rear=s;//将队尾指针指向新加结点
}

bool OutQueue(QueueLink &Q,int &e)
{
    if(Q.front==Q.rear)
       return false;
    Lnode *p=Q.front->next;//p指向需要出队的元素
    e=p->data;//读出队头(表头)指针所指向的下一个结点的值
    Q.front->next=p->next;
    if(p==Q.rear)//如果出队元素为最后一个元素
       Q.rear=Q.front;//将队尾指针指向队头
    free(p);//释放出队元素内存
    return true;
}


