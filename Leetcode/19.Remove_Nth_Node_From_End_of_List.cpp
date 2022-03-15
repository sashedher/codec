// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t=0,k=0;
        ListNode* t1=head;
        while(t1){
            t++;
            t1=t1->next;
        }
        k=t-n;
        if(k==0) return head->next;
        k--;
        t1=head;
        while(k--){
            t1=t1->next;
        }
        t1->next=t1->next->next;
        return head;
    
    }
};