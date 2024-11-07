// https://leetcode.com/problems/binary-tree-pruning/

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
    int maxsum(TreeNode* root){
        if(!root) return 0;
        int l,r;
        l=maxsum(root->left);
        r=maxsum(root->right);
        if(l==0) root->left=nullptr;
        if(r==0) root->right=nullptr;
        return l+r+root->val;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        int sm=maxsum(root);
        if(sm==0) return nullptr;
        return root;
    }
};