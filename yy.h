#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;

}*Linklist,Lnode;


Linklist InitList(Linklist &L)
{
    int x;
    Lnode *s;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",x);
    while(x!=999)
    {
        s=(Lnode*)malloc(sizeof(LNode));
        s->next=L->next;
        s->data=x;
        L->next=s;

   
    scanf("%d",x); }
    return L;
}

LNode* Findlist(int i, Linklist L)//单链表按位查找
{
    if (i<0)
    return NULL;
    Lnode *p=L;
    int j=0;
    while (p!=NULL&&j<i) 
    {
       p=p->next;
       j++;
    }
    return p;


}
Linklist InitList(Linklist &L);
LNode* Findlist(int i, Linklist L);