// https://leetcode.com/problems/create-target-array-in-the-given-order/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> x;
        for(unsigned int i=0;i<nums.size();i++){
            x.insert(x.begin()+index[i],nums[i]);
        }
        return x;
    }
};