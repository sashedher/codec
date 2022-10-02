// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solve(int i,int prev, vector<int> &nums,vector<vector<int>> & dp){
    //     if(i==nums.size()) return 0;
    //     if(dp[i][prev+1]!= -1) return dp[i][prev+1];
    //     int ans=solve(i+1,prev,nums,dp);
    //     if(prev==-1 || nums[prev]<nums[i]){
    //         ans=max(ans, 1+ solve(i+1,i,nums,dp));
    //     }
    //     return dp[i][prev+1]=ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();
        vector<int> next(n+1,0),curr(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int ans=next[prev+1];
                if(prev==-1 || nums[prev]<nums[i]){
                    ans=max(ans, 1+ next[i+1]);
                }
               curr[prev+1]=ans;
            }
            next= curr;
        }
        
        
        return curr[0];
        
    }
};