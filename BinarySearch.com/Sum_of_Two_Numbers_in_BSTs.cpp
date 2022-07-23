// https://binarysearch.com/problems/Sum-of-Two-Numbers-in-BSTs

#include<bits/stdc++.h>
using namespace std;

//using 2 queues comparing every pair of nodes(take advantage of BST) untill target is met, else return false

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};


bool solve(Tree* a, Tree* b, int target) {
    queue<Tree*> q;

    q.push(a);
    while(!q.empty()){
        Tree* t=q.front();
        q.pop();
        queue<Tree*> qt;
        if(t){
            qt.push(b);
            while(!qt.empty()){
                Tree* t2=qt.front();
                qt.pop();
                if(t2){
                    if(t->val + t2->val ==target) return true;
                
                    if( t2->val > abs(t->val-target) )  qt.push(t2->left);
                    else qt.push(t2->right);
                }
            }
        
            if(t->val > target)  q.push(t->left);
            else q.push(t->right);
        }

    }
    return false;
}