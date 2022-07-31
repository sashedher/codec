// https://binarysearch.com/problems/Leaves-in-Same-Level

#include<bits/stdc++.h>
using namespace std;


class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

bool solve(Tree* root) {
    queue<pair<Tree*,int>> q;
    int lvl=-1;

    q.push({root,0});
    while(!q.empty()){
        pair<Tree*,int> t=q.front();
        q.pop();
        if(t.first){
            if(!t.first->left && !t.first->right){
                if(lvl==-1) lvl=t.second;
                else{
                    if(lvl!=t.second) return false;
                }
            }
        
            q.push({t.first->left,t.second+1});
            q.push({t.first->right,t.second+1});
        }
    }
    return true;    
}