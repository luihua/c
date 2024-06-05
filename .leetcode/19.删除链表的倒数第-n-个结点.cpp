// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *h1,*p1,*p2,*ans;
    h1=new ListNode(0,head);
    p1=h1;
    p2=h1;
    for (int i = 0; i < n; i++)
    {
        p2=p2->next;
    }
    
    while (p2->next!=nullptr)
    {
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p1->next->next;
    ans=h1->next;
    delete h1;
    return ans;


    }
};
// @lc code=end

