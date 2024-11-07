// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    int solve(vector<vector<int>> &piles,int x,int n,int k,vector<vector<int>> & dp){
        if(x==n || k==0) return 0;       
        if(dp[x][k]!=-1) return dp[x][k];
        int p=INT_MIN,np=0,sum=0;
        np=solve(piles,x+1,n,k,dp);
        
        for(int i=0,k1=k;i<piles[x].size() && k1>0 ;i++,k1--){
            sum+=piles[x][i];
            p=max(p, solve(piles,x+1,n,k1-1,dp)+sum);
        }   
        return dp[x][k]=max(p,np);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));  
        return solve(piles,0,n,k,dp);
    }
};