// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int l= lower_bound(nums.begin(), nums.end(), target)-nums.begin();
       int u= upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        if(nums.size()==0 || l==nums.size() || nums[l]!=target) return{-1,-1};
        else return {l,u-1};
    }
};