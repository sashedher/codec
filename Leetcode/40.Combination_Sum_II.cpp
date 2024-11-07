// https://leetcode.com/problems/combination-sum-ii/

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
                if(i>0 && cand[i]==cand[i-1]) continue;             // consider only 1st element of idex and ignore remaining equal elements for same index to avoid duplicates
                ans.push_back(cand[i]);
                Backtrack(cand,target-cand[i],ans,i+1);
                ans.pop_back();   
        }
                
                
            
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        Backtrack(candidates,target,ans,0);
        return res;
    }
};