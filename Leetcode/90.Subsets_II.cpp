// https://leetcode.com/problems/subsets-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void Backtrack(vector<int> cand,int n,vector<int> &ans,int ind){
        if(ind>n)    return ;
        res.push_back(ans);            
        
        for(int i=ind;i<cand.size();i++){
                if(i>ind && cand[i]==cand[i-1]) continue;
                ans.push_back(cand[i]);
                Backtrack(cand,n,ans,i+1);
                ans.pop_back();   
        }       
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        Backtrack(nums,nums.size(),ans,0);
        return res;
    }
};