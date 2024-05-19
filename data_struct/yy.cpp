#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "yy.hpp"

int LinkListLength(Linklist L)
{

   Lnode *p=L;
   int i=0;
   while (p!=NULL)
   {
     p=p->next;
     i++;
   }
   return i-1;
   


}

bool PrintLinklist(Linklist L)
{
    if(L->next==NULL)
    {
      printf("NO element\n");
      return false;
    }

    Lnode* p=L;
    int j;
    
    p=p->next;
    
    while (p!=NULL&&p->next!=NULL)
    {
       
       printf("%d->",p->data);
       p=p->next;
    }
    printf("%d\n",p->data);
    return true;
}

Linklist InitList(Linklist &L)//头插法建立单链表.与输入顺序相反
{
    int x;
    Lnode *s;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    printf("element:\n");
    scanf("%d",&x);
    while(x!=999)
    {
        s=(Lnode*)malloc(sizeof(LNode));
        s->next=L->next;
        s->data=x;
        L->next=s;

   
    printf("element:\n");
    scanf("%d",&x); }
    return L;
}
void InsertLinkNode(Linklist &L)
{
	LNode* s;
	int x,Length;
	printf("number:\n");
	scanf("%d", &Length);
	printf("element:\n");
	for (int j = 0; j < Length; j++) {
		s = (LNode*)malloc(sizeof(LNode));//每插入一个元素之前，都需要给它分配节点空间
		scanf("%d", &x);
		s->data = x;
		s->next = L->next;
		L->next = s;
	}

} 

LNode* Findlist(int i, Linklist L)//单链表按位查找
{
    if (i<0)
    return NULL;
    if(i>LinkListLength(L))
    return NULL;
    Lnode *p=L;//p初始指向表头，随循环指向当前节点
    int j=0;//j指示链表位数
    while (p!=NULL&&j<i) 
    {
       p=p->next;
       j++;
    }
    return p;


}
/// @brief 单链表按位数前插
/// @param i 前插的位数
/// @param e 插入值
/// @param L 所插入的单链表
/// @return TRUE ：插入成功 FALSE：插入失败
bool PreInsertNode(int i, int e, Linklist &L)
{
  if(i<1)
    return false;
  
  Lnode *p=L;
  int j=0;

  while (p!=NULL&&j<i)
    {
        p=p->next;
        j++;

    }
  
  if(InsertPriorNode(p, e))
     return true;
  else
     return false;
 





}
bool InsertPriorNode(Lnode *p, int e)//单链表按节点前插
{



    if(p==NULL)
       return false;
    Lnode* s=(Lnode*)malloc(sizeof(Lnode));
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;

    
}

Linklist RInitList(Linklist &L)//尾插法建立单链表.与输入顺序相同
{
    int x;
    Lnode *s=NULL,*r=NULL;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    r=L;//r指向表尾最后一个元素
    printf("element:\n");
    scanf("%d",&x);
    while (x!=999)
    {
        s=(Lnode*)malloc(sizeof(Lnode));//s指向插入的元素
        s->next=r->next;
        s->data=x;
        r->next=s;
        r=s;//插入完成将r指向插入完成的元素及表尾元素
    printf("element:\n");
    scanf("%d",&x);
    }
    
    return L;
    



}
bool InsertNode(int i, int e , Linklist &L)//单链表指定位数后插
{
    if (i<1)
       return false;
    Lnode*p=L;//初始指向头节点
    int j=0;
    while (p!=NULL&&j<i-1)//指针指向插入位数上一位
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
       return false;
    Lnode* s=(Lnode*)malloc(sizeof(Lnode));
    s->next=p->next;
    s->data=e;
    p->next=s;
    return true;
    


    
}

bool DeleteNextNode(Lnode*p, int &DeleteNumber)//节点后删除
{
    if(p==NULL||p->next==NULL)
    return false;
    DeleteNumber=p->next->data;
    free(p->next);
    p->next=p->next->next;
    
    return true;

    

}

bool DeInitLinklist(Linklist &L)
{
    int DeleteNumber=0;
    if (L==NULL)
    {
        printf("error, NO SUCH LINKLIST");
        return false;
    }
    if (L->next=NULL)
    {
        printf("Already A Blank Linklist");
        return true;
    }

    
    
    while (L->next!=NULL)
    {
       if(!DeleteNextNode(L, DeleteNumber));
       return false;
    }
    
    return true;


}

DLinklist InitList(DLinklist &DL)
{
    int x;
    DLnode *s=NULL;
    DL=(DLinklist)malloc(sizeof(DLNode));
    DL->prior=NULL;
    DL->next=NULL;
    printf("Delement:\n");
    scanf("%d",&x);
    while (x=!999)
    {
        s=(DLnode*)malloc(sizeof(DLNode));
        s->data=x;
        s->prior=DL;
        s->next=DL->next;
        DL->next=s;
        printf("Delement:\n");
        scanf("%d",&x);
    }
    return DL;
}

bool PrintLinklist(DLinklist DL)
{
    if(DL->next=NULL)
       return false;

    DLnode *p=DL;
    p=p->next;
    while (p!=NULL&&p->next!=NULL)
    {
        printf("%d<->",p->data);
        p=p->next;
    }
    printf("%d",p->data);
    return true;
    


}




int main()
{  
    int a,e;
    Linklist L=(Linklist)malloc(sizeof(LNode));//申请内存，将指针指向链头
    DLinklist DL=(DLinklist)malloc(sizeof(DLnode));

    L->next=NULL;//建立空链表
    //InsertLinkNode(L);
    InitList(L);
    InitList(DL);
    a=Findlist(3,L)->data;
    printf("Linklist[3]=%d\n",a);
    printf("type a number you want to insert into Linklist\n");
    scanf("%d",&e);
    PreInsertNode(3, e, L);

    if(PrintLinklist(L))
    printf("print complete\n");
    else 
    {
        printf("print error\n");
    }
    printf("length of linklist:%d\n",LinkListLength(L));
    DeInitLinklist(L);

    if(PrintLinklist(DL))
    printf("print complete\n");
    else 
    {
        printf("print erro\n");
    }
   
    free(L);
    free(DL);
    return 0;
    
    
    }