// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

//  similar to 199.Binary_Tree_Right_Side_View.cpp use converse pre order res vector updates untill last right value
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
 

//Function to return a list containing elements of left view of the binary tree.
int height(Node* root){
    if(!root) return 0;
    else return 1+max(height(root->left),height(root->right));
}

void convpre(Node* root,int h,vector<int>& res){
    if(root){
        res[h]=root->data;
        convpre(root->right,h+1,res);
        convpre(root->left,h+1,res);
    }
}
vector<int> leftView(Node* root) {
    int ht=height(root);
    vector<int> res(ht,-101);
    convpre(root,0,res);
    return res;
}