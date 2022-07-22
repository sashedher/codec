// https://binarysearch.com/problems/Top-View-of-a-Tree

#include<bits/stdc++.h>
using namespace std;

// store it in map for every new value and while traversing decrement for left and increment for right

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

vector<int> solve(Tree* root) {
    map<int,int> mp;
    queue<pair<Tree*,int>> q;

    q.push({root,0});
    while(!q.empty()){
        pair<Tree*,int> t=q.front();
        q.pop();
        if(t.first){
            if(mp.find(t.second)==mp.end()) mp.insert({t.second,t.first->val});

            q.push({t.first->left,t.second-1});
            q.push({t.first->right,t.second+1});

        }
    }
    vector<int> res;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        res.push_back(it->second);
    }
    return res;
}