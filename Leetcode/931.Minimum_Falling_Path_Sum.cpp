// https://leetcode.com/problems/minimum-falling-path-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> & mat,int i,int j,int n,vector<vector<int>> &dp){
        if(i<0 || j<0 || j>=n) return INT_MAX;
        
        if(i==0) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=mat[i][j]+ min({solve(mat,i-1,j,n,dp), solve(mat,i-1,j+1,n,dp), solve(mat,i-1,j-1,n,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n= matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res,solve(matrix,m-1,i,n,dp));
        }
        return res;
    }
};