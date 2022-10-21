// https://leetcode.com/problems/contains-duplicate-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j=0,n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                if(i-mp[nums[i]]<=k) return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};