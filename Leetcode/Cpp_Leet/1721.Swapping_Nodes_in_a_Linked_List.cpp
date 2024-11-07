// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        int t=0,r=0;
        int s1,s2;
        
        ListNode* t1=head;
        while(t1){
            t++;
            if(t==k) s1=t1->val;
            t1=t1->next;
        }
        
        r=t-k+1;
        t=0;
        t1=head;
        while(t1){
            t++;
            if(t==r) {
                s2=t1->val;
                break;
            }
            t1=t1->next;
        }
        
        
        t1=head;
        k--;
        while(k--) t1=t1->next;
        t1->val=s2;
        
        
        t1=head;
        r--;
        while(r--) t1=t1->next;
        t1->val=s1;
        
        
        return head;
    }
};