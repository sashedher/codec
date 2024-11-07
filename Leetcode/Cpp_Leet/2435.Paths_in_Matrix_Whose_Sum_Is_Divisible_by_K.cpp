// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j,int k,int sm, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(i<0 || j<0) return 0;
        sm=(sm+grid[i][j])%k;
        if(i==0 && j==0){
            if(sm%k==0) return 1;
            else return 0;
        } 
        if(dp[i][j][sm]!=-1) return dp[i][j][sm];
        

        
        return dp[i][j][sm]=( solve(i,j-1,k,sm,grid,dp) + solve(i-1,j,k,sm,grid,dp))%1000000007;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k,-1)));
       
        return solve(m-1,n-1,k,0,grid,dp);
    }
};