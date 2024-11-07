// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    vector<int> findMode(TreeNode* root) {
        int mx=0;
        map<int,int> mp;
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t){
                mp[t->val]++;
                mx=max(mx,mp[t->val]);
                q.push(t->left);
                q.push(t->right);
            }
        }
        for(map<int,int> ::reverse_iterator it=mp.rbegin();it!=mp.rend();it++){
            if(it->second==mx) res.push_back(it->first);
        }
        
        return res;
    }
};