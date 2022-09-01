// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};


//clear queue for each level and populate with next front node for current node -bfs
class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root){
        queue<Node*> q;
        
        q.push(root);
        while(!q.empty()){
            int t=0,s=q.size();
            
            while(t<s){
                Node* t1=q.front();
                q.pop();
                
                if(t<s-1)   t1->nextRight=q.front();
                else        t1->nextRight=NULL;             //for last node in each level nextRight=NULL
                t++;
                if(t1->left)    q.push(t1->left);
                if(t1->right)   q.push(t1->right);
               
            }
            
        }
    }    
      
};
