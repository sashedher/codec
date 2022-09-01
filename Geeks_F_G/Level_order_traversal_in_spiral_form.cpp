

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 


vector<int> findSpiral(Node *root){
    queue<Node*> q;
    q.push(root);
    vector<int> res;
    int flg=0;  // check left to right -1 or  not -0

    while(!q.empty()){
        int pos=res.size(),lvl=q.size();
        for(int i=0;i<lvl;i++){
            Node* t=q.front();
            q.pop();
            if(t){
                res.push_back(t->data);
                q.push(t->left);
                q.push(t->right);
            }
        }
        if(!flg) reverse(res.begin()+pos,res.end());
        flg=1-flg;
    }
    return res;
}