// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int res,p=0;
    int getDecimalValue(ListNode* head) {
        int t=1,y=0;
        
        if(!head->next) return head->val;
        else{
           res=getDecimalValue(head->next);
            p+=1;
            y=head->val;
            return res+y*pow(2,p);
        }
    }
};