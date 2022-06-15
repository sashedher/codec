// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    
    int Depth(Node* root){
        if(!root) return 0;
        else{
            int mxdepth=0;
            for(int i=0;i<root->children.size();i++){
                int x=Depth(root->children[i]);
                mxdepth=max(mxdepth,x);
            }
            return 1+mxdepth;
        }
        
    }
    
    
    
    
    int maxDepth(Node* root) {
        return Depth(root);
    }
};