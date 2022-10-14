// https://leetcode.com/problems/reorder-list/

#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* LastNode(ListNode* node){
        ListNode* t=node,*t1;
        while(t->next && t->next->next){
            t=t->next;
        }
        t1=t->next;
        t->next=nullptr;
        // cout<<"lastnode :"<<t->val<<endl;
        return t1?t1:t;
    }
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* sp=head,*fp=head;
        while(fp){
            
            fp=fp->next;
            if(fp){
                sp=sp->next;
                fp=fp->next;
            } 
        }
        // cout<<"middleNode :"<<sp->val<<endl;
        ListNode* tp=head,*tmp,*lnode;
        while(tp!=sp){
            tmp=tp->next;
            lnode=LastNode(tmp);
            if(lnode!=tmp) lnode->next=tmp;         //condition to loop to last node refering itself
            tp->next=lnode;
            tp=tmp;
        }
    }
};