// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* nrt=new TreeNode(val,root,nullptr);
            return nrt;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int dpt=1;
        while(!q.empty()){
            int n= q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(depth-1==dpt){
                    if(t){
                        TreeNode* nw=new TreeNode(val,t->left,nullptr);
                        t->left=nw;

                        TreeNode* nw1=new TreeNode(val,nullptr,t->right);
                        t->right=nw1;
                    }
                }
                else{
                    if(t) q.push(t->left);
                    if(t) q.push(t->right);
                }
            }
            dpt=dpt+1;
        }
        
        return root;
    }
};