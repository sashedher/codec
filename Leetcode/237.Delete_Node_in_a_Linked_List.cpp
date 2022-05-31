// https://leetcode.com/problems/delete-node-in-a-linked-list

#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* c;
        c=node;
        c->val=node->next->val;
        c->next=node->next->next;
    }
};