// https://leetcode.com/problems/search-insert-position/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++){
            if(target<=nums[i]) return i;
        }
        return nums.size();
    }
};