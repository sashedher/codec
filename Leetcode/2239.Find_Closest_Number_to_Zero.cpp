// https://leetcode.com/problems/find-closest-number-to-zero/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            if(abs(nums[i])==abs(res)){
                if(nums[i]>0) res=nums[i];
            }
            if(abs(nums[i])<abs(res)) res=nums[i];
                
            
        }
        return res;
    }
};