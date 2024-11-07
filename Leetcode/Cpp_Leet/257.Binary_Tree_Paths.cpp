// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        
        if(!root) return {};
        
        vector<string> res;        
        queue<pair<TreeNode*,vector<int>>> q;
        
        q.push({root,{root->val}});
        while(!q.empty()){
            pair<TreeNode*,vector<int>> t=q.front();
            q.pop();
            if(t.first){
                if(!t.first->left && !t.first->right){
                    vector<int> x=t.second;
                    string ans="";
                    for(int i=0;i<x.size()-1;i++){
                        ans=ans+to_string(x[i])+"->"; 
                    }
                    ans=ans+to_string(x[x.size()-1]);           
                    res.push_back(ans);
                    
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
        
        
        // for(int i=0;i<res.size();i++){
        //     for(int j:res[i]) cout<<j<<" ";
        //     cout<<endl;
        // }
        return res;
        
    }
};