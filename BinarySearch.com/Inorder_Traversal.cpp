// https://binarysearch.com/problems/Inorder-Traversal

#include<bits/stdc++.h>
using namespace std;


class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

void inorder(Tree* root,vector<int>& res){
    if(root){
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
}
vector<int> solve(Tree* root) {
    vector<int> res;
    inorder(root,res);
    return res;
}