// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int pseudoPalindromicPaths (TreeNode* root) {
        int res=0;
        queue<pair<TreeNode*,int>> q;
    
        q.push({root, 1<<root->val });
        while(!q.empty()){
            TreeNode* t=q.front().first;
            int t2=q.front().second;
            q.pop();
           
            if(!t->left && !t->right){
                if( (t2&(t2-1)) ==0 ) res++;
            }
            else{
                if(t->left)     q.push({t->left,t2^(1<<t->left->val)});
                    
            
                if(t->right)    q.push({t->right,t2^(1<<t->right->val)});
            }
            
        }
        
        return res;
    }
};