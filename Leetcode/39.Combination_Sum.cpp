// https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void Backtrack(vector<int> cand,int target,vector<int> &ans,int ind){
        if(target==0){
            res.push_back(ans);
            return ;
        }
        
        if(target<0)    return ;
        
        for(int i=ind;i<cand.size();i++){
                ans.push_back(cand[i]);
                Backtrack(cand,target-cand[i],ans,i);
                ans.pop_back();   
        }
                
                
            
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        Backtrack(candidates,target,ans,0);
        return res;
    }
};