// https://binarysearch.com/problems/Diagonal-Tree-Traversal

#include<bits/stdc++.h>
using namespace std;

// use queue<pair<Tree*,int>>  change int value only moving left and maintain map key as same int and value as sum of node values


class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

vector<int> solve(Tree* root) {
    queue<pair<Tree*,int>> q;
    map<int,int> mp;
    q.push({root,5000});
    while(!q.empty()){
        pair<Tree*,int> t=q.front();
        q.pop();
        if(t.first){
            if(mp.find(t.second)==mp.end()) mp.insert({t.second,t.first->val});
            else mp[t.second]+=t.first->val;

            q.push({t.first->left,t.second+1});
            q.push({t.first->right,t.second});

        }
    }
    vector<int> res;

    for(map<int,int>:: iterator it=mp.begin();it!=mp.end();it++){
        res.push_back(it->second);
    }
    return res;
}