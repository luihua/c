/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

  struct ListNode {
      int val;
      struct ListNode *next;
      
  };
 
typedef struct ListNode lnode;
typedef struct ListNode* linklist;


//思路1：将l1或l2连在对方后面，重新排序
//思路2：每次选择l2的一个结点插入
//迭代法：新建一个空链表，每次取l1,l2较小结点插入
//递归法：






// lnode* insertNode(lnode *pres,lnode *Innode)
// { 
    
//        Innode->next=pres->next;
//        pres->next=Innode;
//        return pres;
   
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
//   lnode *p1=list1,*p2=list2,*s=NULL;
//   int temp;
//   if(list1==NULL)
//     return list2;
//   if(list2==NULL)
//     return list1;
//   for(p2=list2;p2!=NULL;p2=p2->next)
//   {
//       s=(lnode*)malloc(sizeof(lnode));
//       s->val=p2->val;
//       while (p2->val>=p1->val)  
//       {
//          if(p1->next=NULL||p2->val<p1->next->val)
//             insertNode(p1,s);
         
               
//       }
      
//   }
  
  
//   list1->next;
   
   lnode *L=(lnode*)malloc(sizeof(lnode));//分配空间作为头结点，便于返回
   lnode *pre=L;//指向当前被后插结点的指针，便于插入
   while (list1!=NULL&&list2!=NULL)//每次迭代判断是否出现空表
   {
       if(list1->val<=list2->val)//每次将l1和l2中最小的结点插入到pre结点后
       {
            pre->next=list1;
            list1=list1->next;
       }
       else
       {
            pre->next=list2;
            list2=list2->next;
       }
       pre=pre->next;//每次插入将pre指向表尾
   }

/*出现空表，直接将对方全部结点接在pre后*/
   if(list1==NULL)
      pre->next=list2;
   else
      pre->next=list1;
      
return L->next;

   

    
}
// @lc code=end


/*******************************************int main()*********************************************/
/**************************************************************************************************/
int main()
{
    linklist L1,L2;


}
