// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int u=0,l=0;
        ListNode *l1=headA,*l2=headB;
        while(l1){
            u++;
            l1=l1->next;
        }
        while(l2){
            l++;
            l2=l2->next;
        }
        l1=headA;
        l2=headB;
        if(u>l){
            int d=u-l;
            while(d--){
                l1=l1->next;        
            }
        }
        if(l>u){
            int d=l-u;
            while(d--){
                l2=l2->next;        
            }
        }
        while(l1!=l2){
            l1=l1->next;
            l2=l2->next;
        }
        return l1;
        
    }
};