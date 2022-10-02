// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int prev, vector<int> &nums){
        if(i==nums.size()) return 0;
        int ans=solve(i+1,prev,nums);
        if(prev==-1 || nums[prev]<nums[i]){
            ans=max(ans, 1+ solve(i+1,i,nums));
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(0,-1,nums);
    }
};