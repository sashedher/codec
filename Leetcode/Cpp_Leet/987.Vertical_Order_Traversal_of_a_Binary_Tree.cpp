// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,vector<int>> mp;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            map<int,vector<int>> mp1;
            while(n--){                                 // level wise bfs ensures all level elements in same row.
                pair<TreeNode*,int> t=q.front();
                q.pop();
                if(t.first){
                    mp1[t.second].push_back(t.first->val);
                    q.push({t.first->left,t.second-1});
                    q.push({t.first->right,t.second+1});
    
                }
            }
            
            for(map<int,vector<int>>:: iterator it=mp1.begin();it!=mp1.end();it++){
                sort(it->second.begin(),it->second.end());                                              // sort  for same row and column
                mp[it->first].insert(mp[it->first].end(),it->second.begin(),it->second.end());    
            }
        }
        vector<vector<int>> res;
    
        for(map<int,vector<int>>:: iterator it=mp.begin();it!=mp.end();it++){
            res.push_back(it->second);
        }
        
        
        return res;
        
    }
};