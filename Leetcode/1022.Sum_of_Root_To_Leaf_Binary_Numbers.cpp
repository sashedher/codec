// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    int BintoDec(string x){
        int n=x.length(),p=1,res=0;
        for(int i=n-1;i>=0;i--){
            res=res+p*(x[i]-'0');                       //change to int;
            p=p*2;
        }
        cout<<x<<" "<<res<<endl;
        return res;
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        queue<pair<TreeNode*,string>> q;
        string tp="";
        tp.push_back(root->val+'0');
        q.push({root,tp});
        while(!q.empty()){
            pair<TreeNode*,string> t=q.front();
            q.pop();
            if(t.first){
                if(!t.first->left && !t.first->right){
                    sum=sum+BintoDec(t.second);
                }
               if(t.first->left){
                   string temp=t.second;
                   temp.push_back((t.first->left->val+'0'));
                   q.push({t.first->left,temp});
               } 
               if(t.first->right){
                   string temp=t.second;
                   temp.push_back(t.first->right->val+'0');
                   q.push({t.first->right,temp});
               } 
            }
            
        }
        return sum;
    }
};