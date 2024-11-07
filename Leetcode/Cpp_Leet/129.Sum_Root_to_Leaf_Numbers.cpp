// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
    int res=0;
    queue<pair<TreeNode*,int>> q;
    
    q.push({root,0});
    while(!q.empty()){
        pair<TreeNode*,int> t=q.front();
        q.pop();
        if(t.first){
            t.second=(t.second*10)+t.first->val;
            if(!t.first->left && !t.first->right){
                res=res+t.second;
            }
            q.push({t.first->left,t.second});
            q.push({t.first->right,t.second});

        }

    }

    return res;
    
    }
};
