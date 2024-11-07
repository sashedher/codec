// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0,n=nums.size();
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = i; j < n; j++) {
                curr = __gcd(curr, nums[j]);
                res += (curr == k);
            }
        }
    return res;
    }
};