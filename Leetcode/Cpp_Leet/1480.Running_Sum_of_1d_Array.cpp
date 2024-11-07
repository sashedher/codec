// https://leetcode.com/problems/running-sum-of-1d-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            int t=nums[i];
            nums[i]+=s;
            s+=t;
            // cout<<s<<" "<<nums[i]<<endl;
        }
        return nums;
    }
};