// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    
    vector<int> res;
     vector<int> postorder(Node* root) {
        if(root){
            for(int i=0;i<root->children.size();i++){
                postorder(root->children[i]);
            }
            res.push_back(root->val);
            
        }
        return res;
    }
};