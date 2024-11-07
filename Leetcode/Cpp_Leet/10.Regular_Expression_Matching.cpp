// https://leetcode.com/problems/regular-expression-matching/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;                         //both strings exhaust
        if(i>=0 && j<0) return false;                       //if both strings  not exhaust
        if(i<0 && j>=0){                                    // if patterns matching is still exist check for only kleen operator
            for(int k=j;k>=0;k-=2){
                if(p[k]!= '*') return false;
            }
            return true;
        }
        
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(p[j]=='.' || s[i]==p[j] )       return dp[i][j]= solve(i-1, j-1,s,p,dp);             //check remaining string
        
        else if(p[j]=='*')  {
            if(p[j-1]!='.' && p[j-1]!=s[i]) return dp[i][j]= solve(i,j-2,s,p,dp);               //consider * as empty
            else return dp[i][j]= solve(i,j-2,s,p,dp) || solve(i-1,j, s,p,dp);                  //consider * as empty || check with remaining string
        }
        else    return false;
    }
    
    bool isMatch(string &s, string &p) {
        int m=s.length(), n=p.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return solve(m-1,n-1,s,p,dp);
    }
};