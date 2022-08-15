// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int> ans;
            while(n--){
                Node* t=q.front();
                q.pop();
                if(t){
                    ans.push_back(t->val);
                    for(int i=0;i<t->children.size();i++){
                        q.push(t->children[i]);
                    }
                }
            }
            if(ans.size()>0) res.push_back(ans);
            
        }
        
        return res;
    }
};