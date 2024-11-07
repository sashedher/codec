// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> & pric, int i,bool flg, vector<vector<int>> &dp){
        if(i>=pric.size()) return 0;
        if(dp[i][flg]!=-1) return dp[i][flg];
        if(flg)
            return dp[i][flg]= max(-pric[i]+solve(pric,i+1,1-flg,dp), solve(pric, i+1,flg,dp));
        
        else
            return dp[i][flg]= max(pric[i]+solve(pric,i+2,i-flg,dp), solve(pric,i+1,flg,dp));
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};