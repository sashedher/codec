// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool checkBst(TreeNode* root, TreeNode* mn,TreeNode* mx){
        if(!root) return true;
        if(mn && root->val <= mn->val) return false;
        if(mx && root->val >= mx->val) return false;
        
        return checkBst(root->left ,mn, root) && checkBst(root->right,root,mx);
        
              
    }
    bool isValidBST(TreeNode* root) {
       return checkBst(root, nullptr, nullptr);
    }
};