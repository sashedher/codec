// https://leetcode.com/problems/largest-divisible-subset/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n,0);
        sort(nums.begin(), nums.end());
        int res=INT_MIN,ptr;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int pr=0;pr<i;pr++){
                if(nums[i]%nums[pr]==0 && dp[i]<1+dp[pr]){
                    dp[i]=1+dp[pr];
                    hash[i]=pr;
                }
            }
            if(res<dp[i]){
                res=dp[i];
                ptr=i;
            }
        }
        
        vector<int> ans;
        int j=ptr;
        ans.push_back(nums[j]);
        while(hash[j]!=j){
            j=hash[j];
            ans.push_back(nums[j]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};