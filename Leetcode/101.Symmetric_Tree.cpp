

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
    bool isSameTree(TreeNode* p, TreeNode* q) {                 //code from 100.Same_Tree.cpp
        if( (!p && q) || (p&& !q)) return false;
        else if(p && q){
            if(p->val != q->val) return false;
            return isSameTree(p->left, q->right) && isSameTree(p->right,q->left);               // fun call on (left,right) and (right,left)
        }
        else return true;
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root,root);
    }
};