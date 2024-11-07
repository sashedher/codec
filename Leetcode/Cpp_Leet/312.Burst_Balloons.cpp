// https://leetcode.com/problems/burst-balloons/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long cost=INT_MIN;
        for(int k=i;k<=j;k++){
           long x=nums[k]*nums[i-1]*nums[j+1]+ solve(i,k-1,nums,dp)+ solve(k+1,j, nums,dp);
            cost=max(cost, x);
        }
        
        return dp[i][j]=cost;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(1,n,nums,dp);
    }
};