// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t1,*temp=q.front();
            q.pop();
            if(temp){
                t1=temp->left;
                temp->left=temp->right;
                temp->right=t1;
                q.push(temp->left);
                q.push(temp->right);
            }
            
            
        }
        return root;
        
    }
};