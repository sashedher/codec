//  https://leetcode.com/problems/house-robber-ii/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return nums[0];
        vector<int> t(n,0);
        t[1]=nums[0];
        for(int i=2;i<n;i++){
            t[i]=max(t[i-1],t[i-2]+nums[i-1]);
        }
        
        vector<int> d(n,0);
        nums.erase(nums.begin());
        d[1]=nums[0];
        for(int i=2;i<n;i++){
            d[i]=max(d[i-1],d[i-2]+nums[i-1]);
        }

        return max(t[n-1],d[n-1]);
    }
};