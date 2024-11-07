// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        vector<vector<int>> res;        
        queue<pair<TreeNode*,vector<int>>> q;
        
        q.push({root,{root->val}});
        while(!q.empty()){
            pair<TreeNode*,vector<int>> t=q.front();
            q.pop();
            if(t.first){
                if(!t.first->left && !t.first->right){
                    vector<int> x=t.second;
                    int sum=accumulate(x.begin(),x.end(),0);
                    if(sum==targetSum) res.push_back(x);
                }
                if(t.first->left){
                    TreeNode* temp=t.first;
                    vector<int> v=t.second;
                    int num;
                    
                    num=temp->left->val;
                    v.push_back(num);
                    
                    q.push({temp->left,v});
                    
                    
                }   
                if(t.first->right){
                    TreeNode* temp=t.first;
                    vector<int> v=t.second;
                    int num;
                    
                    num=temp->right->val;
                    v.push_back(num);
                    
                    q.push({temp->right,v});
                    
                }  
                
            }
            
        }
        
        return res;
        
        
        
        
    }
};