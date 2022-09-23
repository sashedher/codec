// https://leetcode.com/problems/range-sum-query-immutable/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> presm;
    int sum=0;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            presm.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left>0) return presm[right]-presm[left-1];
        else return presm[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */