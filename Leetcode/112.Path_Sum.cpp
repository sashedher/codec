// https://leetcode.com/problems/path-sum/

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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> t=q.front();
            q.pop();
            if(t.first){
                t.second+=t.first->val;
                if(!t.first->left && !t.first->right){
                    if(t.second==targetSum) return true;
                }
                q.push({t.first->left,t.second});
                q.push({t.first->right,t.second});
                
            }
            
        }
        
        return false;
    }
};