// https://binarysearch.com/problems/Longest-Tree-Path

#include<bits/stdc++.h>
using namespace std;

// similar to diameter of tree

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

int diameter(Tree* root,int &res){
    if(!root) return 0;
    int l,r,temp;
    l=diameter(root->left,res);
    r=diameter(root->right,res);
    temp=1+max(l,r);
    res=max(res,1+l+r);
    return temp;
}

int solve(Tree* root) {
    int res=0;
    diameter(root,res);

    return res;
}