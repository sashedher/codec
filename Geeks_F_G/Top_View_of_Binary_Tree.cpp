// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

// store it in map for every new value and while traversing decrement for left and increment for right


struct Node{
    int data;
    Node* left;
    Node* right;
};


class Solution{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        map<int,int> mp;
        queue<pair<Node*,int>> q;
    
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> t=q.front();
            q.pop();
            if(t.first){
                if(mp.find(t.second)==mp.end()) mp.insert({t.second,t.first->data});
    
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

};



