// https://leetcode.com/problems/sum-of-left-leaves/

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
    
    int sum=0;
    
    void inorder(TreeNode* root,int f){
        if(root){
            inorder(root->left,1);
            if(f==1){
                if(!root->left && !root->right) sum=sum+root->val;
            }
            inorder(root->right,0);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        sum=0;
        inorder(root,0);
        return sum;
    }
};