// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> & pric, int i,bool flg, int ntr,vector<vector<vector<int >>> &dp){
        if(i==pric.size() || ntr==0 ) return 0;
        if(dp[i][flg][ntr]!=-1) return dp[i][flg][ntr];
        if(flg)
            return dp[i][flg][ntr]= max(-pric[i]+solve(pric,i+1,1-flg,ntr,dp), solve(pric, i+1,flg,ntr,dp));
        
        else
            return dp[i][flg][ntr]= max(pric[i]+solve(pric,i+1,i-flg,ntr-1,dp), solve(pric,i+1,flg,ntr,dp));
        
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int >>> dp(prices.size(), vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};