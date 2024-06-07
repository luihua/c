// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
     ListNode *h1,*p1,*p2,*ans;
     h1=new ListNode(0,head);
     p1=h1;
     p2=h1;
     int n=0;
     while (p2->next!=nullptr)
     {
        p2=p2->next;
        n++;
        
     }
     if(n==1||n==0||k==0)
     {
        ans=h1->next;
        // delete h1;
        return ans;
     }
  
     n=k%n; 
     if(n==0||k==0)
     {
        ans=h1->next;
        // delete h1;
        return ans;
     }
        p2->next=h1->next;
     for (int i = 0; i < n; i++)
     {
        p2=p2->next;
     }
     while (p2->next!=p1->next)
     {
        h1=h1->next;
        p2=p2->next;
     }
    


ans=h1->next;
h1->next=nullptr;
return ans;
}
     
};
// @lc code=end

//*******************************************int main()*********************************************/
/**************************************************************************************************/
int main()
{
    Solution S;
    ListNode *head=nullptr,*ans;
    head=new ListNode(0);
    head->next=new ListNode(1);
    head->next->next= new ListNode(2);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next= new ListNode(7);
    // head->next->next->next->next->next->next->next= new ListNode(8);
     ans=S.rotateRight(head,4);
    return 0;
    
}