// https://leetcode.com/problems/longest-string-chain/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(string &a, string &b){
        return a.length()<b.length();
    }
    bool check(string &x, string &y){
        int i=x.length()-1, j=y.length()-1;
        if(i!=j+1) return false;
        
        while(i>=0){
            if(j>=0 && x[i]==y[j]){
                i--;
                j--;
            }
            else    i--;
            
        }
        if(i==-1 && j==-1) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n=words.size(),res=INT_MIN;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int pr=0;pr<i;pr++){
                if(check(words[i],words[pr])){
                    dp[i]=max(dp[i], 1+dp[pr]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
        
    }
};