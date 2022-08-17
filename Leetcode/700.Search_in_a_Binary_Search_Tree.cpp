// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int x) {
        if(root){
            if(root->val == x) return root;
            else if(root->val > x) return  searchBST(root->left,x);
            else return searchBST(root->right,x);
        }        
        
        return nullptr;
    }
};