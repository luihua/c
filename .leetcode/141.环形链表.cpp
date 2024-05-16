// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
**/
 /*Definition for singly-linked list.*/
  struct ListNode {
     int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
  };
 
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int i =1;
        ListNode* p=head;
        // if(head==nullptr||head->next==nullptr)//空表和单节点表无环
        //     return false;
        while (p!=nullptr)
        {
            p=p->next;
            i++;
            if(i==10002)//如果能够循环10001次以上，说明存在环
               return true;
        }
        return false;
            

        
    }
};
// @lc code=end

