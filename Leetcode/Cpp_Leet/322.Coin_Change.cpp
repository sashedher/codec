// https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size(),n=amount;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1 ;i<=n;i++){
            if(i%coins[0]==0) dp[1][i]=i/coins[0];
            else dp[1][i]=INT_MAX-1;
        }
        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){
                    if(coins[i-1]<=j) {
                        dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                    }
                    else{
                        dp[i][j]=dp[i-1][j];

                    }
            }
            
        }
        return dp[m][n]<INT_MAX-1?dp[m][n]:-1;
    }
};
