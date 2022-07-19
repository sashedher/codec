// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-a-binary-tree/1


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 


class Solution {
public:

    void leaf(Node* rt,vector<int>& l){
        if(!rt) return;
        if(!rt->left && !rt->right) l.push_back(rt->data);
        else {
            leaf(rt->left,l);
            leaf(rt->right,l);
            
        }
    }
    
    void leftst(Node* rt,vector<int>& l){
        
        if(!rt) return;
        if(!rt->left && !rt->right)return;
        else{
            l.push_back(rt->data);
            if(rt->left)  leftst(rt->left,l);
            else if(rt->right) leftst(rt->right,l);
        }
    }
    
    void rightst(Node* rt,vector<int>& l){
        
        if(!rt) return;
        if(!rt->left && !rt->right)return;
        else{
            
            if(rt->right)  rightst(rt->right,l);
            else if(rt->left) rightst(rt->left,l);
            l.push_back(rt->data);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> l;
        stack<Node*> sl,sr;
        l.push_back(root->data);
        if(!root->right && !root->left) return l;
        leftst(root->left,l);
        leaf(root,l);
        rightst(root->right,l);
        
        
        return l;
    }
};