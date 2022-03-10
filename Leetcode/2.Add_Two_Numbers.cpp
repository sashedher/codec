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
        int c=0,s=0,x=0,y=0;
        
        ListNode *p1=new ListNode(0,nullptr);
        head=p1;
        while((t1 || t2)  || c!=0){
            x=!t1?0:t1->val;
            y=!t2?0:t2->val;
            
            ListNode *p2=new ListNode(0,nullptr);
            p1->next=p2;
            p1=p2;
            
            s=x+y+c;
            c=s/10;
            s%=10;
            p1->val=s;
            t1=t1?t1->next:nullptr;
            t2=t2?t2->next:nullptr;
           
            
        }
        
        
        return head->next;
        
    }
};