// https://leetcode.com/problems/palindrome-partitioning-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[2001][2001];
    bool checkPalin(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
         return true;
    }
    
     int solve(string s,int i,int j){
        if(i>=j) return 0;
        if(checkPalin(s,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
         int ans=INT_MAX;
        
        for(int k=i;k<j;k++){
            if(checkPalin(s,i,k)) ans=min(ans,1+solve(s,k+1,j));
        }
        
         return  dp[i][j]=ans;

    }

    
    
    int minCut(string s) {
        
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};