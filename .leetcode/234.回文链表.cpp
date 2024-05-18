// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    bool isPalindrome(ListNode* head) {
        ListNode *p=nullptr,*q,*phead;
        q=new ListNode(0);
        p=new ListNode(0,head);//插入头节点便于输出
        phead=p;
        while (p->next!=nullptr)
        {
            q->next=new ListNode(p->next->val,q->next);
            p=p->next;
            
        }
        while(q->next!=nullptr)
        {
            
            if(phead->next->val!=q->next->val)
            return false;
            q=q->next;
            phead=phead->next;
        }
        return true;
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
//     head->next->next->next->next->next = new ListNode(2);
//     head->next->next->next->next->next->next= new ListNode(2);
//     head->next->next->next->next->next->next->next= new ListNode(1);
//     S.isPalindrome(head);
//     return 0;
// }