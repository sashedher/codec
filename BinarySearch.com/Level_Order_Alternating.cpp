// https://binarysearch.com/problems/Level-Order-Alternating

#include<bits/stdc++.h>
using namespace std;

//reverse sub array when all the values of that level are inserted

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

vector<int> solve(Tree* root) {

    queue<Tree*> q;
    q.push(root);
    vector<int> res;
    int flg=1;  // check left to right -1 or  not -0

    while(!q.empty()){
        int pos=res.size(),lvl=q.size();
        for(int i=0;i<lvl;i++){
            Tree* t=q.front();
            q.pop();
            if(t){
                res.push_back(t->val);
                q.push(t->left);
                q.push(t->right);
            }
        }
        if(!flg) reverse(res.begin()+pos,res.end());
        flg=1-flg;
    }
    return res;
}