// https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax=0,maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curMax+=nums[i];
            maxSum=max(curMax,maxSum);
            if(curMax<0) curMax=0;
        }
        return maxSum;
    }
};