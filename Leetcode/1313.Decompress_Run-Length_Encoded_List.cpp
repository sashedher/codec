// https://leetcode.com/problems/decompress-run-length-encoded-list/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i+=2){
            vector<int> temp(nums[i],nums[i+1]);
            res.insert(res.end(),temp.begin(), temp.end());
        }
        return res;
    }
};