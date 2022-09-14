// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> & v, int i){
    if(i<0) return 0; 
    return max( v[i]+rec(v,i-2), rec(v,i-1) );
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
         dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}