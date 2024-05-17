// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA,*pb=headB;
        char  scan_onceA=0,scan_onceB=0;
        if(pa==nullptr||pb==nullptr)
            return nullptr;
        while(!(pa==pb&&pa!=nullptr)){
            if(pa!=nullptr)
                pa=pa->next;
            else
            {
                pa=headB;
                scan_onceA++;
            }
            if(pb!=nullptr)
               pb=pb->next;
            else
            {
                pb=headA;
                scan_onceA++;
            }
            if (scan_onceA==4)
            {
                return nullptr;
            }
            
        }
        return pa;
    }
};
// @lc code=end
int main(){
    Solution S;
    ListNode *heada=nullptr;
    ListNode *headb=nullptr;
    heada=new ListNode(4);
    heada->next=new ListNode(1);
    heada->next->next= new ListNode(8);
    heada->next->next->next = new ListNode(4);
    heada->next->next->next->next = new ListNode(5);
    // heada->next->next->next->next->next = new ListNode(4);
    // heada->next->next->next->next->next->next= new ListNode(4);
    // heada->next->next->next->next->next->next->next= new ListNode(4);
    headb=new ListNode(5);
    headb->next=new ListNode(6);
    headb->next->next= new ListNode(1);
    headb->next->next->next= heada->next->next;
    ListNode* intsec;
    intsec=S.getIntersectionNode(heada,headb);
    if(intsec==nullptr)
    std::cout << "null" << std::endl;
    std::cout << intsec->val << std::endl;
    return  0;
}
