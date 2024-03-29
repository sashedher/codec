// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long res=0;
        int jmin=-1,jmax=-1,jbad=-1,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==minK) jmin=i;
            if(nums[i]==maxK) jmax=i;
            if(nums[i]>maxK || nums[i]<minK) jbad=i;
            
            res+= (long) max(0,min(jmin,jmax)- jbad);
        }
        
        return res;
    }
};