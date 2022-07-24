// https://binarysearch.com/problems/Sum-of-the-Deepest-Nodes

#include<bits/stdc++.h>
using namespace std;

//when depth is equal to curr_depth add value to result if depth updates reset result to zero and start again

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

int solve(Tree* root) {
    queue<pair<Tree*,int>> q;
    int d=INT_MIN,res=0;

    q.push({root,0});
    while(!q.empty()){
        pair<Tree*,int> t=q.front();
        q.pop();
        if(t.first){
            if(t.second>d){
                d=t.second;
                res=0;
            }
            if(t.second==d) res+=t.first->val;

            q.push({t.first->left,t.second+1});
            q.push({t.first->right,t.second+1});
        }
    }
    return res;
}