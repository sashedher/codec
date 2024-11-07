// https://leetcode.com/problems/binary-tree-upside-down/

#include<bits/stdc++.h>
using namespace std;

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
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* rt;
    void flip(TreeNode* prev, TreeNode* curr){
        if(curr){
            flip(curr,curr->left);
            curr->right=prev;
            if(prev)curr->left=prev->right;
            else curr->left=NULL;
        }
        else rt=prev;
    }
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        flip(NULL,root);
        return rt;
    }
};