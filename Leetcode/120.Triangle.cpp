// https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> &tri, int i,int j,int n,vector<vector<int>> &dp){
        if(i==n-1) return tri[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = tri[i][j]+ min(solve(tri,i+1,j,n,dp), solve(tri,i+1,j+1,n,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,n,dp);
    }
};