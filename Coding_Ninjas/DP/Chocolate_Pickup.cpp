// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j1,int j2, int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    if(j1<0 || j2<0 || j1>=c || j2>=c) return INT_MIN;
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int res=INT_MIN;
    for(int k1=-1;k1<2;k1++){
        for(int k2=-1;k2<2;k2++){
            if(j1==j2) res=max(grid[i][j1]+solve(i+1,j1+k1,j2+k2,r,c,grid,dp),res);
            else res=max(grid[i][j1]+grid[i][j2]+solve(i+1,j1+k1,j2+k2,r,c,grid,dp),res);
        }
    }
    return dp[i][j1][j2]=res;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
//     memset(dp,-1,sizeof(dp));
    return solve(0,0,c-1,r,c,grid,dp);
}