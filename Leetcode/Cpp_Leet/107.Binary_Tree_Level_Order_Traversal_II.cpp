// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*,int>> bfs;
        vector<pair<int,int>> res;
        int height=0;
        
        bfs.push({root,0});
        while(!bfs.empty()){
            pair<TreeNode*,int> t=bfs.front();
            bfs.pop();
            if(t.first){
                res.push_back({t.first->val,t.second});
                bfs.push({t.first->left,t.second+1});
                bfs.push({t.first->right,t.second+1});
                height=max(height,t.second+1);
            }
            
        }
        
        
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i].first<<" "<<res[i].second<<endl;
        // }
        // cout<<height;
        
        vector<vector<int>> ans(height);
        for(int i=0;i<res.size();i++){
            ans[height-1-res[i].second].push_back(res[i].first);
            
        }
        
        
        
        return ans;
        
        
        
    }
};