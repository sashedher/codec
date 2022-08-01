// https://binarysearch.com/problems/Leaf-Equivalent-Trees

#include<bits/stdc++.h>
using namespace std;


class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

void leafNodes(Tree* node,vector<int>& v1){
    if(!node) return;
    if(!node->left && !node->right) v1.push_back(node->val);
    else{
        leafNodes(node->left,v1);
        leafNodes(node->right,v1);
    }
}
bool solve(Tree* root0, Tree* root1) {
    vector<int> t1,t2;
    
    leafNodes(root0,t1);
    leafNodes(root1,t2);
    
    int n=t1.size(),m=t2.size();
    if(n!=m) return false;
    for(int i=0;i<n;i++){
        if(t1[i]!=t2[i]) return false;
    }
    return true;
}