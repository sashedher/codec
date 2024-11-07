// https://leetcode.com/problems/cousins-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,-1}});
        int d1=0,d2=-1,p1=-1,p2=-1;
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> t=q.front();
            q.pop();
            if(t.first){
                if(t.first->val==x){
                    d1=t.second.first;
                    p1=t.second.second;
                } 
                if(t.first->val==y) {
                    d2=t.second.first;
                    p2=t.second.second;
                }
                
                q.push({t.first->left,{t.second.first+1,t.first->val}});
                q.push({t.first->right,{t.second.first+1,t.first->val}});
            }
        }
        
        return d1==d2 && p1!=p2;
    }
};