// https://binarysearch.com/problems/Level-Order-Traversal

#include<bits/stdc++.h>
using namespace std;


class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

vector<int> solve(Tree* root) {
    queue<Tree*> q;
    vector<int> res;

    q.push(root);
    while(!q.empty()){
        Tree* t=q.front();
        q.pop();
        if(t){
            res.push_back(t->val);
            q.push(t->left);
            q.push(t->right);
        }
    }
    return res;
}