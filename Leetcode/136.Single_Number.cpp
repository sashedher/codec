// https://leetcode.com/problems/single-number/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r=0;
        for(int x:nums){
            r=r^x;
        }
        return r;
    }
};