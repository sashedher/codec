// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        int depth=-1;
        queue<pair<TreeNode*,int>> q;
        int res=0;
        
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> t=q.front();
            q.pop();
            if(t.first){
                if(!t.first->left && !t.first->right){
                    if(t.second>depth){
                        res=t.first->val;                   //updates only  for left most leaf at every level
                        depth=t.second;                     //update depth for every level
                    } 
                }
                if(t.first->left) q.push({t.first->left,t.second+1});
                if(t.first->right) q.push({t.first->right,t.second+1});
            }
        }
        
        return res;
        
    }
};