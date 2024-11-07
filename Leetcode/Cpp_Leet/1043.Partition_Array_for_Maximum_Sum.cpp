// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<int>&dp){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mx=INT_MIN,res=INT_MIN,len=0,n=arr.size();
        for(int j=i; j < min(n, i+k) ; j++){
            len++;
            mx=max(mx,arr[j]);
            res=max(res, len*mx+ solve(j+1,k,arr,dp));
        }
        return dp[i]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return solve(0,k,arr,dp);
    }
};