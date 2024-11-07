// https://leetcode.com/problems/decode-ways/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, string &s,vector<int> &dp){
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int d=s[i]-'0';
        int ans=0;
        if(d==0) return 0;
        else{
            dp[i]=ans= solve(i+1,s,dp);
            if(i<s.length()-1) {
                d=d*10+s[i+1]-'0';
                // cout<<d<<endl;
                if(d<=26) dp[i]=ans+=solve(i+2,s,dp);
            }
        }
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return solve(0,s,dp);
    }
};