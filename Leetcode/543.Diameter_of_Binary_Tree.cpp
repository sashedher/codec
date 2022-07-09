// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameter(TreeNode* node,int & res){
        if(!node) return 0;
        int l,r,temp;
        l=diameter(node->left,res);
        r=diameter(node->right,res);
        temp=1+max(l,r);
        res=max(res,l+r);
        
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        diameter(root,res);
        return res;
    }
};