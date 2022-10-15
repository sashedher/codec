// https://leetcode.com/problems/minimize-maximum-of-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long s=nums[0],mx=s,res=INT_MIN;
        for(int i=1;i<n;i++){
            s+=nums[i];
            if(nums[i]>mx){
                mx=ceil((s*1.0)/(i+1));

            }
            res=max(mx,res);
        }
        return res;
    }
};