// https://binarysearch.com/problems/Tree-Traversal

#include<bits/stdc++.h>
using namespace std;

// use stack to store parents and pop when move is upwards

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

int solve(Tree* root, vector<string>& moves) {
    stack<Tree*> st;
    Tree* node=root;
    int n=moves.size();
    int res=-1;
    
    for(int i=0;i<n;i++){
        if(moves[i]=="RIGHT"){
            st.push(node);
            node=node->right;
        }
        else if(moves[i]=="LEFT"){
            st.push(node);
            node=node->left;
        }
        else{
            node=st.top();
            st.pop();
        }
    }
    return node->val;
}