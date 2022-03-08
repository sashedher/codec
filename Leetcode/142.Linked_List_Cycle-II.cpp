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
       set<ListNode *> s; 
        ListNode *t1=head;
        s.insert(head);
        while(t1){
            t1=t1->next;
            if(s.find(t1) != s.end()) return t1;
            s.insert(t1);
            
        }
        return NULL;
        
    }
};