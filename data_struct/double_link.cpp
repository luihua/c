/**
 * @file double_link.cpp
 * @author jia (1075524832@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "yy.hpp"  
extern int x;



/// @brief 初始化带头结点的双向链表
/// @param DL  链表指针
/// @return 
DLinklist InitList(DLinklist &DL)
{

    DL=(DLinklist)malloc(sizeof(DLNode));
    DL->prior=NULL;
    DL->next=NULL;
    return DL;
}

/// @brief 在P结点后插结点
/// @param p 双向链表某一结点p
/// @param x 插入链表结点对应的元素
/// @return 
bool  InsertNode(DLnode *p,int x)
{
    
    DLnode *s=NULL;//用于存储插入结点
    if(p==NULL)//p为空指针，插入错误
      return false;
    // printf("Delement:\n");
    // scanf("%d",&x);
    // while (x=!999)
    // {
    s=(DLnode*)malloc(sizeof(DLNode));
    s->data=x;
    s->prior=p;
    s->next=p->next;
    p->next=s;
    // printf("Delement:\n");
    //scanf("%d",&x);
    // }
    return true;
}


/// @brief p结点前插结点
/// @param p 结点
/// @param x 插入节点对应的元素
/// @return 
bool PreInsertNode(DLnode *p, int x)
{
    DLnode *s=NULL;//用于存储插入结点
    if(p==NULL)//p为空指针，插入错误
      return false;
    if(p->prior==NULL);//p为头结点，插入错误
      return false;
    s=(DLnode*)malloc(sizeof(DLnode));
    s->data=x;
    s->next=p;
    s->prior=p->prior;
    p->prior->next=s;
    p->prior=s;
    return true;

}





bool PreInstructLink(DLinklist &DL)
{
    
    int x;//存储每次插入的值
   
    printf("Double Link Element:\n");
    scanf("%d",&x);
    while(x!=999)
    {
        if(!InsertNode(DL,x))
           return false;
        printf("Double Link Element:\n");
        scanf("%d",&x);
        

    }
    return true;



}

bool DeleteNode(DLnode *p,int &e)
{
    if(p==NULL)
      return false;
    if(p->next==NULL)
      return false;
    DLnode *q;
    q=p->next;
    e=q->data;  
    p->next=q->next;
    if(q->next!=NULL)
      p->next->prior=p;
    free(q);
    return true;  
      

}

bool PrintLinklist(DLinklist DL)
{
    if(DL->next==NULL||DL==NULL)
    {
       printf("empty Linklist\n");
       return false;
    }
    DLnode *p=DL;
    p=p->next;
    while (p!=NULL&&p->next!=NULL)
    {
        printf("%d<->",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
    return true;
    


}

bool DeInitLinklist(DLinklist &DL)
{

   if(DL==NULL)
    return false;
   if(DL->next==NULL)
    return true;
   
   while (DL->next!=NULL)
   {
     DeleteNode(DL,x);
   }
   return true;
   
   
}

int x; 

int main()
{
  int x=1;
    DLinklist DL;
    InitList(DL);
    PreInstructLink(DL);
    PrintLinklist(DL);
    DeleteNode(DL,x);
    PrintLinklist(DL);
    DeInitLinklist(DL);
    PrintLinklist(DL);
    free(DL);
    return 0;
}
