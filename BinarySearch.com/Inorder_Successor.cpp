// https://binarysearch.com/problems/Inorder-Successor

#include<bits/stdc++.h>
using namespace std;

//traverse from root to leaf. update result if only node is greater than t and maintain min among them

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};




int solve(Tree* root, int t) {
    int res=INT_MAX;
    Tree* node=root;

    while(node){
        if(node->val >t){
            res=min(res,node->val);
            node=node->left;
        }
        else node=node->right;
    }
    return res;
}