// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        
        q.push(root);
        while(!q.empty()){
            int n=q.size();
        
            vector<int> tp;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                if(t){
                    tp.push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            if(tp.size()>0){
                long long int sum=0;
                sum=accumulate(tp.begin(),tp.end(),sum);
                double x=(double)sum/tp.size();
                res.push_back(x);
            }
                
        }
        return res;
        
    }
};