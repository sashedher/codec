// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* t1=head;
        ListNode* t2;
        ListNode* temp=head->next;
        while(t1 && t1->next){
            t2=t1;
            t1=t1->next;
            t2->next=t1->next;
            t1->next=t2;
            t1=t2->next;
            if(t1 && t1->next) t2->next=t1->next;
            else t2->next=t1;
        }
        return temp;
    }
};