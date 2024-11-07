// https://leetcode.com/problems/contains-duplicate

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        if(s.size()< nums.size()) return true;
        else return false;
        
    }
};