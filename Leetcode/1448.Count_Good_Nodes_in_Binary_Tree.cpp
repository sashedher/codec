// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int c=0;
        
        q.push({root,root->val});
        while(!q.empty()){
            pair<TreeNode*,int> tp=q.front();
            
            q.pop();
            if(tp.first){
                int mx=tp.second;
                if(tp.first->val >= tp.second) {
                        mx=tp.first->val;
                    
                            c++;
                }
                q.push({tp.first->left,mx});
                q.push({tp.first->right,mx});
            }
        }
        
        return c;
        
    }
};