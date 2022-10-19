// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(string &a, string &b){
        if(a.length()==b.length()) return a>b;
        else return a.length() > b.length();
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(),compare);
        for(auto x:nums) cout<<x<<" ";
        return nums[k-1];
    }
};