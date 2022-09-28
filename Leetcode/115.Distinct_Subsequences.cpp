// https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s,string &t,vector<vector<int>> &dp){
        if(j<0) return 1;                                                       //when t is completely matched
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);         //when s & t char equal count remaining char's with and with out considering
        }
        else return dp[i][j]=solve(i-1,j,s,t,dp);                              // if not matched comapare with remaining charecters of string s
        
    }
    int numDistinct(string &s, string &t) {
        int m=s.length(), n= t.length();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};