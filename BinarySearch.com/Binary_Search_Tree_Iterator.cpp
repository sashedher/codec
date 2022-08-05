// https://binarysearch.com/problems/Binary-Search-Tree-Iterator

#include<bits/stdc++.h>
using namespace std;

//store the tree nodes in queue using inorder traversal and return according to function calls

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

class BSTIterator {
    public:
    queue<Tree*> q;
    void inorder(Tree* root,queue<Tree*>& q){
        if(root){
            inorder(root->left,q);
            q.push(root);
            inorder(root->right,q);
        }
    }
    BSTIterator(Tree* root) {
        inorder(root,q);
    }

    int next() {
        if(hasnext()){
            Tree* t=q.front();
            q.pop();
            return t->val;
        }
        return 0;
    }

    bool hasnext() {
        return !q.empty();
    }
};