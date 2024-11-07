// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        queue<pair<TreeNode*,int>> q;
        int depth=10e6;                     //based on given constraints
        
        q.push({root,1});
        while(!q.empty()){
            pair<TreeNode*,int> t=q.front();
            q.pop();
            if(t.first){
             if(!t.first->left && !t.first->right){             //update depth for leaf nodes
                    depth=min(depth,t.second);
                }
                q.push({t.first->left,t.second+1});
                q.push({t.first->right,t.second+1});   
            }
                
            
        }
        return depth;
    }
};