// https://leetcode.com/problems/add-two-numbers/

#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
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
        ListNode *t1=l1,*t2=l2,*head;
        int c=0,s=0;
        
        ListNode *p1=new ListNode(0,nullptr);
        head=p1;
        while(t1 && t2){
            
            ListNode *p2=new ListNode(0,nullptr);
            p1->next=p2;
            p1=p2;
            
            s=t1->val+t2->val+c;
            c=s/10;
            s%=10;
            p1->val=s;
            t1=t1->next;
            t2=t2->next;
           
            
        }
        if(t1){
            while(t1){
                
                ListNode *p2=new ListNode(0,nullptr);
                p1->next=p2;
                p1=p2;
                
                s=t1->val+c;
                c=s/10;
                s%=10;
                p1->val=s;
                t1=t1->next;
                
            }
        }
         if(t2){
            while(t2){
                
                ListNode *p2=new ListNode(0,nullptr);
                p1->next=p2;
                p1=p2;
                
                
                s=t2->val+c;
                c=s/10;
                s%=10;
                p1->val=s;
                t2=t2->next;
               
            }
        }
        if(c>0) {
             ListNode *p2=new ListNode(0,nullptr);
                p1->next=p2;
                p1=p2;
                
                p1->val=c;
            
        }
        
        
        return head->next;
        
    }
};