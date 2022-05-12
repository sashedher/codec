// https://leetcode.com/problems/count-sorted-vowel-strings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count=0;
    void Backtrack(string s,int n,int index,string ans){
        if(ans.length()==n) {
            count++;
            cout<<ans<<" ";
            return;
        }
        for(int i=index;i<s.length();i++){
                ans.push_back(s[i]);
                Backtrack(s,n,i,ans);
                ans.pop_back();
            
        }
    }
        
        
        
    int countVowelStrings(int n) {
        vector<vector<int>> dp(51,vector<int>(6,0));
        for(int i=0;i<6;i++){
            dp[1][i]=1;
        }
        dp[1][0]=5;
        for(int i=2;i<51;i++){
            for(int j=1;j<6;j++){
                dp[i][j]=accumulate(dp[i-1].begin()+j,dp[i-1].end(),0);
                
            }
            dp[i][0]=accumulate(dp[i].begin()+1,dp[i].end(),0);
            
        }
        
        
        
        // Backtrack("aeiou",n,0,"");
        return dp[n][0];
    }
};