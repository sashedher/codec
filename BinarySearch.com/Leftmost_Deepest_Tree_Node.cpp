// https://binarysearch.com/problems/Leftmost-Deepest-Tree-Node

#include<bits/stdc++.h>
using namespace std;

// whenever depth is updating store node value in result and return after traversing

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};



int solve(Tree* root) {
    queue<pair<Tree*,int>> q;
    int res=-1,d=INT_MIN;

    q.push({root,0});
    while(!q.empty()){
        pair<Tree*,int> t=q.front();
        q.pop();
        if(t.first){
            if(t.second>d){
                d=t.second;
                res=t.first->val;
            }
            q.push({t.first->left,t.second+1});
            q.push({t.first->right,t.second+1});

           
        }
    }   
    return res; 
}