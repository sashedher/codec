// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[501][501];
    bool checkPalin(string s,int i,int j){
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
            int left=0,right=0;
            
            if(dp[i][k]!=-1) left=dp[i][k];
            else left=solve(s,i,k);
            
            if(dp[k+1][j]!=-1) right=dp[k+1][j];
            else right=solve(s,k+1,j);
            
            int t= left+ right+ 1;
            ans=min(ans,t);
        }
        dp[i][j]=ans;
        return ans;
    }
    
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
        
    }
};