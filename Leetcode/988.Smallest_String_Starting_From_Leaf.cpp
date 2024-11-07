// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string smallestFromLeaf(TreeNode* root) {
        vector<string> res;
        queue<pair<TreeNode*,string>> q;
        
        string x="";
        char y=97+root->val;
        x=x+y;
        
        q.push({root,x});
        while(!q.empty()){
            
            pair<TreeNode*,string> t=q.front();
            q.pop();
            if(!t.first->left && !t.first->right){
                reverse(t.second.begin(), t.second.end());
                string tp=t.second;
                
                res.push_back(tp);
            }
            
            
            if(t.first->left){
                char z=97;
                z+=t.first->left->val;
                q.push({t.first->left,t.second+z});
            }
            if(t.first->right){
                char z=97;
                z+=t.first->right->val;
                q.push({t.first->right,t.second+z});
            }   
        }
        sort(res.begin(),res.end());
        for(string g: res) cout<<g<<" ";
        
        
        return res[0];
        
    }
};