// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
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
            ans[res[i].second].push_back(res[i].first);
            
        }
        res.clear();
        
        vector<double> result;
        for(int i=0;i<ans.size();i++){
            double temp=0;
            long long int sum=0;
            sum=accumulate(ans[i].begin(),ans[i].end(),static_cast<long long int>(0));     
            temp=sum*1.0/ans[i].size();
            result.push_back(temp);
        }
        
        
        return result;
        
    }
};