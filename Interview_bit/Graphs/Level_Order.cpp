// https://www.interviewbit.com/problems/level-order/

#include<bits/stdc++.h>
using namespace std;



class Solution{
public: 
    
    // Definition for binary tree
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    vector<vector<int> > Solution::levelOrder(TreeNode* A) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(A);
        while(!q.empty()){
            int n=q.size();
            vector<int> ans;
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t){
                    ans.push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);    
                } 
            }
            if(ans.size()>0)  res.push_back(ans);
        }
        return res;
    }


};