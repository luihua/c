// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) { 
        ListNode* post=head;//指向目前访问的结点
        if (post==nullptr)//空表
          return post;
        while(post->next!=nullptr)//循环访问直到节点的下一节点指向null
        {
            while(post->next->val==post->val)//如果当前节点与下一节点值相同
            {
                 post->next=post->next->next;//删除下一节点
                 if(post->next==nullptr)//删除节点后下一节点指向NULL则表明链表已访问完毕
                   return head;
            }
            post=post->next;//相邻两节点值不同则进入下一节点     
        }
        return head;
    }
};
// @lc code=end


/*******************************************int main()*********************************************/
/**************************************************************************************************/
int main()
{
    Solution S;
    int i=0;

    ListNode *head=nullptr;

    head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next= new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next= new ListNode(4);
    head->next->next->next->next->next->next= new ListNode(4);
    head->next->next->next->next->next->next->next= new ListNode(4);
    
    S.deleteDuplicates(head);

    return 0;

  


}