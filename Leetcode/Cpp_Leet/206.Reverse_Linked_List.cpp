// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* head1;
    void reverse(ListNode* prev, ListNode* curr){
        if(curr){
            reverse(curr,curr->next);
            curr->next=prev;
        }
        else head1=prev;
    }
    ListNode* reverseList(ListNode* head) {
      reverse(nullptr,head);
      return head1;
        
    }
    
};