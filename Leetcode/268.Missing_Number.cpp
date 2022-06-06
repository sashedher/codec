// https://leetcode.com/problems/missing-number

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
        for(int i=0;i<=nums.size();i++){
            s=s^i;
        }
        for(int i:nums){
            s=s^i;
        }
        return s;
    }
};