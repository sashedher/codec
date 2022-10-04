// https://leetcode.com/problems/house-robber-iii/

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
    
    int solve(TreeNode* root,map<TreeNode*,int> &mp){
        if(!root) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        
        int nr=0,r=root->val;
        nr=solve(root->left,mp);
        nr+=solve(root->right,mp);
        if(root->left){
            r+=solve(root->left->left,mp);
            r+=solve(root->left->right,mp);
        }
        if(root->right){
            r+=solve(root->right->left,mp);
            r+=solve(root->right->right,mp);
        }
        return mp[root]= max(nr,r);
    }
    
    int rob(TreeNode* root) {
        map<TreeNode*,int> mp;
        return solve(root,mp);
    }
};