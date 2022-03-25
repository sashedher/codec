// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 
#include<bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t1=head;
        while(t1){
            if(t1->next && t1->val == t1->next->val){
                t1->next=t1->next->next;
            }
            else t1=t1->next;
        }
        return head;
    }
};