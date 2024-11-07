// https://leetcode.com/problems/subarray-product-less-than-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prd=1,n=nums.size(),res=0;
        
        for(int lf=0, rgt=0; rgt<n; rgt++){
            prd*= nums[rgt];
            while(prd>=k) prd/=nums[lf++];
            res=res+rgt-lf+1;
        }
        return res;
    }
};