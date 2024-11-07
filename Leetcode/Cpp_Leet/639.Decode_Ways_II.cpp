// https://leetcode.com/problems/decode-ways-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long solve(int i, string &s, vector<long> &dp){
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int d;
        if(s[i]!='*') d=s[i]-'0';
        long ans=0;
        if(d==0) return 0;
        else{
            if(s[i]=='*'){
                for(int dx=1;dx<=9;dx++){
                    d=dx;
                    ans+= solve(i+1,s,dp)%1000000007;
                    if(i<s.length()-1) {
                        if(s[i+1]=='*')
                        {
                            for(int dy=1;dy<=9;dy++){
                                if(d*10+dy<=26) ans+=solve(i+2,s,dp)%1000000007;
                            }
                        
                        }
                        else{
                            d=d*10+s[i+1]-'0';
                            // cout<<d<<endl;
                            if(d<=26) ans+=solve(i+2,s,dp)%1000000007;
                        }
                        
                    }
                }
            }
            else{
                ans+= solve(i+1,s,dp)%1000000007;
                if(i<s.length()-1) {
                    if(s[i+1]=='*')
                        {
                            for(int dy=1;dy<=9;dy++){
                                if(d*10+dy<=26) ans+=solve(i+2,s,dp)%1000000007;
                            }
                        
                        }
                        else{
                            d=d*10+s[i+1]-'0';
                            // cout<<d<<endl;
                            if(d<=26) ans+=solve(i+2,s,dp)%1000000007;
                        }
                }
            }
            
        }
        return dp[i]=ans%1000000007;
    }
    
    int numDecodings(string s) {
        vector<long> dp(s.length()+1,-1);
        return solve(0,s,dp)%1000000007;
    }
};