// https://leetcode.com/problems/recover-binary-search-tree


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
    
    TreeNode* lnode=nullptr,*n1=nullptr,*n2=nullptr;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            if(lnode && lnode->val > root->val){
                if(n1){
                    n2=root;
                    return;
                }
                else{
                    n1=lnode;
                    n2=root;
                }
            }
            
            lnode=root;
            
            inorder(root->right);
        }
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(n1->val,n2->val);
    }
};