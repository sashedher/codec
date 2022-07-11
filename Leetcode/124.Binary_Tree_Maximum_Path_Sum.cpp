// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int pathsum(TreeNode* node,int &res){
        if(!node) return 0;
        int l,r,temp,ans;
        l=pathsum(node->left,res);
        r=pathsum(node->right,res);
        
        temp=max(max(l,r)+node->val,node->val);      //temp -> passing current value through current node to its parent wheather considering its child subtrees or not
        ans=max(temp,node->val+l+r);                 //ans  -> if sum is greater than left subtrr + cuur node val + right Sub tree
        res=max(ans,res);
        
        return temp;
        
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        pathsum(root,res);
        
        return res;
    }
};