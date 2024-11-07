// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> t=q.front();
            q.pop();
            int x=t.first->val+t.second;
            // cout<<x<<" "<<t.first->val<<endl;
            
            if(t.first){
                if(!t.first->left && !t.first->right){          //count sum pn leaf nodes
                    sum=sum+x;
                    // cout<<x<<endl;
                }
               if(t.first->left){
                   
                   q.push({t.first->left,x<<1});            //when level changes left shift x val
               } 
               if(t.first->right){
                   
                   q.push({t.first->right,x<<1});            //when level changes left shift x val
               } 
            }
            
        }
        return sum;
    }
};