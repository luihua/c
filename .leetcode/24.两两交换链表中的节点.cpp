
/*************************************************************************************************/
//每次交换遍历节点的后两个节点，之后将遍历节点后移两位dump->1->2->..，dump->2->1->..,如果节点为单数，p1->next.next为null停止，节点为偶数，p1.next=null停止
/*************************************************************************************************/

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
 * };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *h1,*p1,*temp;
        h1=new ListNode(0,head);
        p1=h1;
        while(p1->next!=nullptr&&p1->next->next!=nullptr)
        {
            temp=p1->next;
            p1->next=temp->next;
            temp->next=p1->next->next;
            p1->next->next=temp;
            p1=p1->next->next;
        }
    ListNode *ans=h1->next;
    delete h1;
    return ans;

    }
};
// @lc code=end

