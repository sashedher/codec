

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        int flg=1;  // check left to right- 1 else- 0

        while(!q.empty()){
            int lvl=q.size();
            vector<int> ans;
            for(int i=0;i<lvl;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t){
                    ans.push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            if(!flg) reverse(ans.begin(),ans.end());
            flg=1-flg;
            if(ans.size()>0) res.push_back(ans);
        }
        
        return res;
    }
};