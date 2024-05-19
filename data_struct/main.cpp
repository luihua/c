
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "yy.hpp"


int main()
{  
    int a,e;
    Linklist L=(Linklist)malloc(sizeof(LNode));//申请内存，将指针指向链头
    L->next=NULL;//建立空链表
    //InsertLinkNode(L);
    RInitList(L);
    a=Findlist(3,L)->data;
    printf("Linklist[3]=%d\n",a);
    scanf("%d",&e);
    printf("linklist length=%d",LinkListLength);
    PreInsertNode(3, e, L);

    if(PrintLinklist(L))
    printf("print complete");
    else 
    {
        printf("print error");
    }
    
   
    free(L);
    return 0;
    }