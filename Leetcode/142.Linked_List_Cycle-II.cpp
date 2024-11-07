// https://leetcode.com/problems/linked-list-cycle-ii/

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
   ListNode *detectCycle(ListNode *head) {
       ListNode *t2,*t1;
        if(!head) return NULL;
        t1=head;
        t2=t1;
        while(t2 && t2->next){
            t1=t1->next;
            t2=t2->next->next;
            if(t1==t2) break;
            
        }
        if(!t2  || !t2->next) return NULL;
        t1=head;
        while(t1){
            if(t1==t2) return t1;
            t1=t1->next;
            t2=t2->next;
        }
        return NULL;
        
    }
};