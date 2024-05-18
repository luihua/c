/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode *p=nullptr;
      p= new ListNode(0,head);//新增头结点，便于输出和操作元素
      ListNode*p1=p;
      
    
        
        while(p->next!=nullptr)//循环至倒数第二个结点
        {
            while(p->next->val==val)//移除满足的节点
            {
                p->next=p->next->next;
                if (p->next==nullptr)//移除后next指向空，直接输出
                {
                    return p1->next;
                }
                
            }
            
                p=p->next;//对于不满足的结点直接遍历
        }
        return p1->next;
    }
};
// @lc code=end


/*******************************************int main()*********************************************/
/**************************************************************************************************/
// int main()
// {
//     Solution S;
//     ListNode *head=nullptr;
//     head=new ListNode(1);
//     head->next=new ListNode(2);
//     head->next->next= new ListNode(2);
//     head->next->next->next = new ListNode(3);
//     head->next->next->next->next = new ListNode(3);
//     head->next->next->next->next->next = new ListNode(4);
//     head->next->next->next->next->next->next= new ListNode(4);
//     head->next->next->next->next->next->next->next= new ListNode(4);
//     S.removeElements(head,2);
//     return 0;
// }