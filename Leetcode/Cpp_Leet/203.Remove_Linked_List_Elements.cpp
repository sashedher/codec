// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
          while(head && head->val==val) head=head->next;
        ListNode *t2,*t1=head;
        if(head) t2=t1;
        while(t2){
            if(t2->val==val){
                t1->next=t2->next;
                t2=t2->next;
            }
            else{ 
                t1=t2;
                t2=t2->next;
            }
        }
        return head;
        
    }
};