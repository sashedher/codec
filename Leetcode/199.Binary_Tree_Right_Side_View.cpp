// https://leetcode.com/problems/binary-tree-right-side-view/submissions/
// either use pre order or converse preorder

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
    int height(TreeNode* root){
        if(!root) return 0;
        else return 1+max(height(root->left),height(root->right));
    }
    
    void convpre(TreeNode* root,int h,vector<int>& res){
        if(root){
            if(res[h]==-101){
                res[h]=root->val;
            }
            convpre(root->right,h+1,res);
            convpre(root->left,h+1,res);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        int ht=height(root);
        vector<int> res(ht,-101);
        convpre(root,0,res);
        return res;
    }
};