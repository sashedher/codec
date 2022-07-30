// https://binarysearch.com/problems/Left-Side-View-of-a-Tree

#include<bits/stdc++.h>
using namespace std;

// converse preorder and store values in res vector of size equal to height of tree

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

int depth(Tree* root){
    if(!root) return 0;
    else return 1+max(depth(root->left),depth(root->right));
}
void convpre(pair<Tree*,int> t,vector<int>& res){
    if(t.first){
        res[t.second]=t.first->val;
        convpre({t.first->right,t.second+1},res);
        convpre({t.first->left,t.second+1},res);
    }
}

vector<int> solve(Tree* root) {
    int d=depth(root);
    vector<int> res(d,0);
    convpre({root,0},res);
    return res;
}