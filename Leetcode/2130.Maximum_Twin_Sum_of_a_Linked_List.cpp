// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/



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
    int pairSum(ListNode* head) {
        vector<int> res;
        while(head){
            res.push_back(head->val);
            head=head->next;
        }
        int n=res.size(),mx=INT_MIN;
        for(int i=0;i<n/2;i++){
            mx=max(mx,res[i]+res[n-i-1]);
        }
        return mx;
            
    }
};