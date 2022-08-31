// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[2][201][201]={{{-1}}};
    int solve(string s,int i,int j,char ck){
        if(i>j) return 0;
        if(i==j){
          if(ck=='T') return s[i]=='T';
          else return s[i]=='F';
        }
        if(ck=='T'){
            if(dp[1][i][j]!=-1) return dp[1][i][j];
            
        }
        else{
            if(dp[0][i][j]!=-1) return dp[0][i][j];
        }
        
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int lt,lf,rt,rf;
            
            if(dp[1][i][k-1]!=-1) lt=dp[1][i][k-1];
            else dp[1][i][k-1]=lt=solve(s,i,k-1,'T');
            
            if(dp[0][i][k-1]!=-1) lf=dp[0][i][k-1];
            else dp[0][i][k-1]=lf=solve(s,i,k-1,'F');
            
            if(dp[1][k+1][j]!=-1) rt=dp[1][k+1][j];
            else dp[1][k+1][j]=rt=solve(s,k+1,j,'T');
            
            if(dp[0][k+1][j]!=-1) rf=dp[0][k+1][j];
            else dp[0][k+1][j]=rf=solve(s,k+1,j,'F');
            
            
            
            if(s[k]=='&'){
                if(ck=='T') ans+= lt*rt;
                else ans+= lt*rf + lf*rt + lf*rf;
            }
            
            else if(s[k]=='|'){
                if(ck=='T') ans+= lt*rf + lf*rt + lt*rt;
                else ans+= lf*rf;
            }
            else if(s[k]=='^'){
                if(ck=='T') ans += lt*rf + lf*rt;
                else ans+= lf*rf + lt*rt;
            }
        }
        if(ck=='T'){
             dp[1][i][j]=ans;
            
        }
        else{
             dp[0][i][j]=ans;
        }
        return ans%1003;
        
    }

    
    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return solve(S,0,S.length()-1,'T');
    }
};
