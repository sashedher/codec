// https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> & grid, int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0 ) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j] = grid[i][j]+min( solve(grid,i-1,j,dp), solve(grid, i,j-1,dp) );
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
         return solve(grid,m-1,n-1,dp);
    }
};