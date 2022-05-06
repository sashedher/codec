// https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        vector<int> num;
        ListNode *l1=head;
        while(l1){
            num.push_back(l1->val);
            l1=l1->next;
        }
        sort(num.begin(),num.end());
        l1=head;
        int i=0;
        while(l1){
            l1->val=num[i++];
            l1=l1->next;
        }
        return head;
    }
};