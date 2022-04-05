// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        int t=0;
        ListNode* t1=head;
        while(t1){
            t++;
            t1=t1->next;
        }
        if(t==1) return head;
        t=t/2;
        
        t1=head;
        while(t--){
            t1=t1->next;
        }
        return t1;
    }
    
};