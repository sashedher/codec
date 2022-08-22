// https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnivalTree(TreeNode* root) {
        int ck=root->val;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t){
                if(t->val!= root->val) return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        
        return true;
    }
};