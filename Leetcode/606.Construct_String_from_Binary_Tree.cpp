// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string res="";
    
    void preorder(TreeNode* root){
        if(root){
            
            res=res+"(";
            res=res+to_string(root->val);
            if(!root->left && root->right) res=res+"()";
            
            preorder(root->left);
            preorder(root->right);
            
            res=res+")";
        }
    }
    
    
    string tree2str(TreeNode* root) {
        res="";
        preorder(root);
        res.erase(0,1);
        res.erase(res.length()-1,1);
        return res;
    }
};