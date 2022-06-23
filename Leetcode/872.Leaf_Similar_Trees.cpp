// https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        stack<TreeNode*> q1;
        
        q1.push(root1);
        while(!q1.empty()){
            TreeNode* t=q1.top();
            q1.pop();
            if(t){
                if(!t->left && !t->right) r1.push_back(t->val);
                q1.push(t->right);
                q1.push(t->left);
            }
        }
        // for(int x:r1) cout<<x<<" ";
        // cout<<endl;
       
        q1.push(root2);
        while(!q1.empty()){
            TreeNode* t=q1.top();
            q1.pop();
            if(t){
                if(!t->left && !t->right) r2.push_back(t->val);
                q1.push(t->right);
                q1.push(t->left);
            }
        }
//         for(int x:r2) cout<<x<<" ";
//         cout<<endl;
        
        
        if(r1.size()!=r2.size()) return false;
        int n=r1.size();
        for(int i=0;i<n;i++){
            if(r1[i]!=r2[i]) return false;
        }
        return true;
    }
};