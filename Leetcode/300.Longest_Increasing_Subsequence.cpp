// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int prev, vector<int> &nums,vector<vector<int>> & dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!= -1) return dp[i][prev+1];
        int ans=solve(i+1,prev,nums,dp);
        if(prev==-1 || nums[prev]<nums[i]){
            ans=max(ans, 1+ solve(i+1,i,nums,dp));
        }
        return dp[i][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};