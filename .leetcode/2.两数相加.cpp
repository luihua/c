// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1,*h2,*p1,*p2,*h3,*p3;
        int i=0,temp=0;
        h1= new ListNode(0,l1);
        p1=h1;
        h2= new ListNode(0,l2);
        p2=h2;
        h3=new ListNode(0);
        p3=h3;

        while (p1->next!=nullptr&&p2->next!=nullptr)
        {
            
            
            // if(i==0){
                
            //     h3->next->val=(p1->next->val+p2->next->val)%10;
            //     temp=p1->next->val+p2->next->val
            // }
            // else{
                
                temp=p1->next->val+p2->next->val+i;
                
                p3->next = new ListNode((temp)%10);       
                //temp=p1->next->val+p2->next->val+i;        
            // }
            if(temp>=10){
                i=1;
            }
            else{
                i=0;
            }
            p3=p3->next;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1->next==nullptr)
        {
            while (p2->next!=nullptr)
            {
                temp=p2->next->val+i;
                p3->next = new ListNode((temp)%10);   
                if(temp>=10){
                    i=1;
                }
                else{
                    i=0;
                }
                p3=p3->next;
                p2=p2->next;    
            }
            
        }
        if(p2->next==nullptr)
        {
            while (p1->next!=nullptr)
            {
                temp=p1->next->val+i;
                p3->next = new ListNode((temp)%10);   
                if(temp>=10){
                    i=1;
                }
                else{
                    i=0;
                }
                p3=p3->next;
                p1=p1->next;    
            }
            
        }
        if(i==1)
        {
            p3->next = new ListNode(1);
        }
    return h3->next;


    }
};
// @lc code=end
//*******************************************int main()*********************************************/
/**************************************************************************************************/
int main()
{
    Solution S;
    ListNode *head=nullptr,*head1=nullptr,*head2;
    head=new ListNode(9);
    head->next=new ListNode(9);
    head->next->next= new ListNode(9);
    head1=new ListNode(9);
    head1->next=new ListNode(9);
    head1->next->next= new ListNode(9);
    head1->next->next->next= new ListNode(9);
    head2=S.addTwoNumbers(head,head1);
    while (head2!=nullptr)
    {
        std::cout << head2->val;
        head2=head2->next;
    }
    cout<< std::endl;
    

    return 0;
    
}

