// https://leetcode.com/problems/palindrome-partitioning-iv/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkPalin(string &s,int i,int j, vector<vector<int>>& dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]=0;
        if(s[i]==s[j]) return dp[i][j]= checkPalin(s,i+1,j-1,dp);
        return dp[i][j]=0;
    }

    
    bool checkPartitioning(string s) {
       int n=s.length(),i=1,j=n-2;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n-2;i++){
            for(int j=n-1;j>i+1;j--){
               
                // if(dp[0][i]==-1)    dp[0][i]= checkPalin(s,0,i);      
                // if(dp[i+1][j-1]==-1)    dp[i+1][j-1]= checkPalin(s,i+1,j-1);
                //   if(dp[j][n-1]==-1)  dp[j][n-1]=checkPalin(s,j,n-1);
                
                if( checkPalin(s,0,i,dp) && checkPalin(s,i+1,j-1,dp) && checkPalin(s,j,n-1,dp) ) return true;
            }
        }
        
        return false;
    }
};