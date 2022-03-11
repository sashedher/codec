// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* h1=head;
        int s=0;
        if(!head) return head;
        
        while(h1){
            s++;
            h1=h1->next;
        }
        k=k%s;
        while(k--){
            ListNode *l1=head;
            int t1,t2;
            t1=l1->val;
            while(l1->next){
                t2=l1->next->val;
                l1->next->val=t1;
                t1=t2;
                l1=l1->next;
            }
        head->val=t2;
            
        }
        return head; 
    }
};