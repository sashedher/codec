// https://leetcode.com/problems/linked-list-cycle/

#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *t2,*t1;
        if(!head) return false;
        t1=head;
        t2=t1;
        while(t2 && t2->next){
            t1=t1->next;
            t2=t2->next->next;
            if(t1==t2) return true;
            
        }
        return false;
        
    }
};