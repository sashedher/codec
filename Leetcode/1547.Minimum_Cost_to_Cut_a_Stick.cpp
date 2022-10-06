// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int cost=INT_MAX;
        for(int k=i;k<=j;k++){
           int x=cuts[j+1]-cuts[i-1]+ solve(i,k-1,cuts,dp)+ solve(k+1,j, cuts,dp);
            cost=min(cost, x);
        }
        
        return dp[i][j]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        vector<vector<int>> dp(sz+1,vector<int>(sz+1,-1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(1,sz,cuts,dp);
    }
};